#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <vector>
#include "simulacao.h"
using namespace std;

extern const string RESET, BLUE, MAG, CYAN;

void cls();
void print_titulo();
string colorir(const string &s, const string &code);
void print_frames(const vector<Frame> &frames, int start, int len, int replaced_idx = -1, int hit_idx = -1, int new_idx = -1); // função para mostrar os frames

#endif