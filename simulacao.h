#ifndef SIMULACAO_H
#define SIMULACAO_H

#include <vector>
#include <string>

using namespace std;

enum Modo { GLOBAL = 0, LOCAL = 1 };
enum Algoritmo { FIFO = 0, OPTIMAL = 1, CLOCK = 2 };

struct Acesso {
    int pid;
    int page;
    bool write; // true = write, false = read
};

struct Frame {
    int pid;
    int page;
    bool valid; // true = ocupado
    bool dirty; // true = pagina alterada
    bool refbit; // CLOCK - usado pra saber se a pagina foi referenciada
    Frame() : pid(-1), page(-1), valid(false), dirty(false), refbit(false) {}
};

// Funções 
bool parse_token(const string &tok, Acesso &a);
void run_simulation(const vector<Acesso> &seq, int total_frames, Modo modO, Algoritmo alg, int num_procs);

#endif
