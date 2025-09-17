#include "util.h"
#include <iostream>

using namespace std;

const string RESET = "\033[0m";
const string BLUE = "\033[94m";
const string MAG = "\033[95m";
const string CYAN = "\033[96m";

void cls()
{
    system("cls");
}

string colorir(const string &texto, const string &cor)
{
    return cor + texto + RESET;
}

void print_titulo()
{
    cout << R"(
        _____ _           _       _              _        _____                   _        _____ _     _           _
       |   __|_|_____ _ _| |___ _| |___ ___    _| |___   |     |___ _____ ___ ___|_|___   |  |  |_|___| |_ _ _ ___| |
       |__   | |     | | | | .'| . | . |  _|  | . | -_|  | | | | -_|     | . |  _| | .'|  |  |  | |  _|  _| | | .'| |
       |_____|_|_|_|_|___|_|__,|___|___|_|    |___|___|  |_|_|_|___|_|_|_|___|_| |_|__,|   \___/|_|_| |_| |___|__,|_|)";
}

void print_frames(const vector<Frame> &frames, int start, int len, int replaced_idx, int hit_idx, int new_idx)
{
    cout << " +";
    for (int i = start; i < start + len; i++)
        cout << "----------+";
    cout << "\n ";

    for (int i = start; i < start + len; i++)
    {
        string cell;
        if (frames[i].valid)
        {
            string page_s = to_string(frames[i].page);
            string dirty_s = frames[i].dirty ? "D" : " ";
            string core = page_s + dirty_s;
            if ((int)core.size() < 7)
                core = string(7 - core.size(), ' ') + core;
            cell = " " + core + " ";
        }
        else
            cell = "    -    ";

        if (i == replaced_idx)
            cout << "|" << colorir(cell, MAG);
        else if (i == hit_idx)
            cout << "|" << colorir(cell, CYAN);
        else if (i == new_idx)
            cout << "|" << colorir(cell, BLUE);
        else
            cout << " |" << cell;
    }
    cout << " |\n +";
    for (int i = start; i < start + len; i++)
        cout << "----------+";
    cout << "\n ";

    for (int i = start; i < start + len; i++)
    {
        string meta;
        if (frames[i].valid)
        {
            string pid_s = "P" + to_string(frames[i].pid);
            string ref_s = frames[i].refbit ? "R" : " ";
            string dirty_s = frames[i].dirty ? "D" : " ";
            meta = " " + pid_s + " " + ref_s + " " + dirty_s + " ";
            if ((int)meta.size() < 9)
                meta += string(9 - meta.size(), ' ');
        }
        else
            meta = "         ";

        if (i == replaced_idx)
            cout << "|" << colorir(meta, MAG);
        else if (i == hit_idx)
            cout << "|" << colorir(meta, CYAN);
        else if (i == new_idx)
            cout << "|" << colorir(meta, BLUE);
        else
            cout << " |" << meta;
    }
    cout << " |\n +";
    for (int i = start; i < start + len; i++)
        cout << "----------+";
    cout << "\n";
}
