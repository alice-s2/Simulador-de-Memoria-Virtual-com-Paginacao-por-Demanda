#include "simulacao.h"
#include "util.h"
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
    // inicialização de variáveis
    vector<Acesso> sequencia;
    int frames = 0, num_procs = 1;
    Algoritmo alg = FIFO;
    Modo modo = GLOBAL;
    bool tem_seq = false, tem_frames = false, tem_alg = false, tem_modo = false;

    while (true)
    {
        cls();
        print_titulo();

        cout << "\n\n\n";
        cout << " 1) Inserir sequencia de acessos as paginas\n\n"
             << " 2) Definir numero de frames disponiveis\n\n"
             << " 3) Escolher algoritmo de substituicao:\n    [0] FIFO\n    [1] OPTIMAL\n    [2] CLOCK / Second-Chance\n\n"
             << " 4) Modo de alocacao:\n    [0] Global\n    [1] Local\n\n"
             << " 5) Iniciar simulacao\n\n"
             << " 0) Sair\n\n"
             << " ---------------------------------------------------------------------------------------------------------------------\n\n";

        cout << " Sequencia: " << (tem_seq ? "[ok]" : "[x]") << "\n"
             << " Frames: " << (tem_frames ? to_string(frames) : "[x]") << "\n"
             << " Algoritmo: " << (tem_alg ? (alg == FIFO ? "FIFO" 
                                           : alg == OPTIMAL ? "OPTIMAL"
                                           : alg == CLOCK ? "CLOCK" : "-") : "[x]") << "\n"; 
        cout << " Modo: " << (tem_modo ? (modo == GLOBAL ? "GLOBAL" : "LOCAL") : "[x]") << "\n\n"
             << " Opcao: ";

        int op;
        if (!(cin >> op))
        {
            cin.clear();
            cin.ignore();
            continue;
        }
        cin.ignore();
        switch (op)
        {
        case 0:
            cout << " Saindo...\n";
            return 0;

        case 1:
        {
            cout << " Digite a sequencia de paginas:\n > ";
            string line;
            getline(cin, line);
            stringstream ss(line);
            sequencia.clear();
            string tok;
            bool ok = true;
            while (ss >> tok)
            {
                Acesso a;
                if (!parse_token(tok, a))
                {
                    ok = false;
                    break;
                }
                sequencia.push_back(a);
            }
            if (ok && !sequencia.empty())
                tem_seq = true;
            else
                cout << " Entrada invalida! Tente novamente.\n";
            break;
        }

        case 2:
            cout << " Frames totais: ";
            cin >> frames;
            cin.ignore();
            tem_frames = true;
            break;

        case 3:
            cout << " [0] FIFO [1] OPTIMAL [2] CLOCK: ";
            int a;
            cin >> a;
            cin.ignore();
            if (a >= 0 && a <= 2)
            {
                alg = (Algoritmo)a;
                tem_alg = true;
            }
            break;

        case 4:
            cout << " [0] GLOBAL [1] LOCAL: ";
            int m;
            cin >> m;
            cin.ignore();
            if (m == 0)
            {
                modo = GLOBAL;
                num_procs = 1;
                tem_modo = true;
            }
            else
            {
                modo = LOCAL;
                cout << " Processos: ";
                cin >> num_procs;
                cin.ignore();
                tem_modo = true;
            }
            break;

        case 5:
            if (tem_seq && tem_frames && tem_alg && tem_modo)
            {
                run_simulation(sequencia, frames, modo, alg, num_procs);
            }
            else
            {
                cout << " Preencha 1-4!\n";
                cin.get();
            }
            break;

        default:
            break;
        }
    }

    return 0;
}
