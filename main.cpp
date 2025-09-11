#include <iostream>
using namespace std;

int main() {
    while(true)
    {
        system("cls");
        cout << R"(
         _____ _           _       _              _        _____                   _        _____ _     _           _
        |   __|_|_____ _ _| |___ _| |___ ___    _| |___   |     |___ _____ ___ ___|_|___   |  |  |_|___| |_ _ _ ___| |
        |__   | |     | | | | .'| . | . |  _|  | . | -_|  | | | | -_|     | . |  _| | .'|  |  |  | |  _|  _| | | .'| |
        |_____|_|_|_|_|___|_|__,|___|___|_|    |___|___|  |_|_|_|___|_|_|_|___|_| |_|__,|   \___/|_|_| |_| |___|__,|_|)";
    
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
        case 1:
            break;
        case 2:
            break;
        case 3:     
            break;
        case 4: 
            break;
        case 5:
            break;
        case 0:
            cout << " Saindo...\n";
            return 0;
        default:
            break;
        }
    }

    return 0;
}
