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
};
