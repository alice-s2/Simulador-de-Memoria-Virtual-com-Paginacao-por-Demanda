#include "simulacao.h"
#include "util.h"
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// ---- Funções auxiliares ----
int find_frame(const vector<Frame> &frames, int start, int len, int pid, int page)
{
    for (int i = start; i < start + len; ++i)
    {
        if (frames[i].valid && frames[i].pid == pid && frames[i].page == page)
            return i;
    }
    return -1;
}

int next_use_index(const vector<Acesso> &seq, int cur_idx, int pid, int page)
{
    for (size_t k = cur_idx + 1; k < seq.size(); ++k)
        if (seq[k].pid == pid && seq[k].page == page)
            return (int)k;
    return INT_MAX / 2;
}

int choose_victim_optimal(const vector<Frame> &frames, const vector<Acesso> &seq, int cur_idx, int start, int len)
{
    int victim = -1, farthest = -1;
    for (int i = start; i < start + len; ++i)
    {
        int ni = next_use_index(seq, cur_idx, frames[i].pid, frames[i].page);
        if (ni > farthest)
        {
            farthest = ni;
            victim = i;
        }
    }
    return victim;
}

int choose_victim_fifo(queue<int> &q, vector<Frame> &frames, int start, int len)
{
    while (!q.empty())
    {
        int idx = q.front();
        q.pop();
        if (idx >= start && idx < start + len)
            return idx;
    }
    return start;
}

int choose_victim_clock(vector<Frame> &frames, int &ptr, int start, int len)
{
    while (true)
    {
        int idx = start + (ptr % len);
        if (!frames[idx].refbit)
        {
            ptr = (ptr + 1) % len;
            return idx;
        }
        else
        {
            frames[idx].refbit = false;
            ptr = (ptr + 1) % len;
        }
    }
}

bool parse_token(const string &tok, Acesso &a)
{
    string t = tok;
    bool write = false;
    if (!t.empty() && (t.back() == 'W' || t.back() == 'w'))
    {
        write = true;
        t.pop_back();
    }
    if (!t.empty() && (t.back() == 'R' || t.back() == 'r'))
    {
        write = false;
        t.pop_back();
    }
    size_t p = t.find(':');
    int pid = 1;
    string page_s;
    if (p == string::npos)
        page_s = t;
    else
    {
        pid = stoi(t.substr(0, p));
        page_s = t.substr(p + 1);
    }
    if (page_s.empty())
        return false;
    a.pid = pid;
    a.page = stoi(page_s);
    a.write = write;
    return true;
}

// ---- Simulação ----
void run_simulation(const vector<Acesso> &seq, int total_frames, Modo modo, Algoritmo alg, int num_procs)
{
    vector<Frame> frames(total_frames);
    vector<int> proc_frames(num_procs + 1, 0);
    vector<int> proc_start(num_procs + 1, 0);

    if (modo == LOCAL)
    {
        int base = total_frames / num_procs;
        int rem = total_frames % num_procs;
        int cur = 0;
        for (int p = 1; p <= num_procs; ++p)
        {
            proc_frames[p] = base + (p <= rem ? 1 : 0);
            proc_start[p] = cur;
            cur += proc_frames[p];
        }
    }
    else
    {
        proc_frames[1] = total_frames;
        proc_start[1] = 0;
    }

    queue<int> fifo_q;
    vector<int> clock_ptr(num_procs + 1, 0);

    int hits = 0, faults = 0, page_outs = 0;
    bool auto_run = false;

    for (size_t idx = 0; idx < seq.size(); ++idx)
    {
        const Acesso &ac = seq[idx];

        int pool_start, pool_len;
        if (modo == GLOBAL)
        {
            pool_start = proc_start[1];
            pool_len = proc_frames[1];
        }
        else
        {
            pool_start = proc_start[ac.pid];
            pool_len = proc_frames[ac.pid];
        }

        int found = find_frame(frames, pool_start, pool_len, ac.pid, ac.page);
        int replaced = -1, hit = -1, newp = -1;

        if (found != -1)
        {
            // HIT
            ++hits;
            frames[found].refbit = true;
            if (ac.write)
                frames[found].dirty = true;
            hit = found;
        }
        else
        {
            // FAULT
            ++faults;
            int victim = -1;
            // procura frame livre no pool
            for (int i = pool_start; i < pool_start + pool_len; ++i)
                if (!frames[i].valid)
                {
                    victim = i;
                    break;
                }
            if (victim == -1)
            {
                if (alg == FIFO)
                    victim = choose_victim_fifo(fifo_q, frames, pool_start, pool_len);
                else if (alg == OPTIMAL)
                    victim = choose_victim_optimal(frames, seq, (int)idx, pool_start, pool_len);
                else if (alg == CLOCK)
                    victim = choose_victim_clock(frames, clock_ptr[(modo == GLOBAL ? 1 : ac.pid)], pool_start, pool_len);
            }
            replaced = victim;
            if (frames[victim].valid && frames[victim].dirty)
                ++page_outs;

            frames[victim].pid = ac.pid;
            frames[victim].page = ac.page;
            frames[victim].valid = true;
            frames[victim].dirty = ac.write;
            frames[victim].refbit = true;
            fifo_q.push(victim);
            newp = victim;
        }
    }
}