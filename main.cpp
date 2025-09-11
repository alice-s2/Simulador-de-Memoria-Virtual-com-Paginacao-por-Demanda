#include "simulacao.h"
#include "util.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    // inicialização de variáveis
    vector<Acesso> sequencia;
    int frames = 0, num_procs = 1;
    Algoritmo alg = FIFO;
    Modo modo = GLOBAL;
    string linha;

    while(true)
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
        << " ---------------------------------------------------------------------------------------------------------------\n\n";

        cout << " Sequencia: \n"
             << " Frames: \n"
             << " Algoritmo: \n"  
             << " Modo: \n\n" 
             << " Opcao: ";

        int op;
        cin >> op;
        switch (op)
        {
        case 0:
            cout << " Saindo...\n";
            return 0;

        case 1:
            cout << " Digite a sequencia: ";
            linha.clear();
            getline(cin, linha);
            sequencia.clear();
            break;

        case 2:
            cout << " Digite o numero de frames: ";
            cin >> frames; cin.ignore();
            break;

        case 3:  
            cout << " Escolha o algoritmo (0 = FIFO  1 = OPTIMAL  2 = CLOCK): ";
            int a;
            cin >> a; cin.ignore();
            break;

        case 4: 
            cout << " Escolha o modo (0 = GLOBAL  1 = LOCAL): ";
            int m;
            cin >> m; cin.ignore();
            if(m==0){
                modo = GLOBAL; 
                num_procs = 1;
            } else {
                modo = LOCAL;
                cout << " Numero de processos: ";
                cin >> num_procs; cin.ignore();
            }
            break;

        case 5:
            break;
        default:
            break;
        }
    }

    return 0;
}
