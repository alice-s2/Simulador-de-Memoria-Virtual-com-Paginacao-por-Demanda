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