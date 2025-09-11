#include <string>
using namespace std;

const string RESET, BLUE, MAG, CYAN;

void enableVTMode(); // função para habilitar cores ANSI no Windows
string colorir(); 
void print_frames(); // função para mostrar os frames

