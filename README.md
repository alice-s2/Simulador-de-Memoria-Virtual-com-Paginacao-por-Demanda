# Simulador de Memória Virtual

Feito por Alice Neumann e Gabriel Trentini Teixeira

## Descrição do Projeto

Este projeto é um simulador interativo de memória virtual com paginação por demanda, desenvolvido para demonstrar e visualizar o funcionamento de diferentes algoritmos de substituição de páginas.

O simulador permite explorar conceitos fundamentais de sistemas operacionais, como page-fault, localidade de referência e thrashing. Ele oferece a capacidade de configurar o número de frames de memória, a sequência de acessos e o algoritmo de substituição, exibindo o processo passo a passo no terminal.

## Tópico Escolhido

O simulador aborda a Memória Virtual com Paginação por Demanda, focando nos seguintes conceitos e requisitos:

- Page-fault: Simulação do evento e do carregamento de páginas na memória.

- Algoritmos de Substituição: Implementação e comparação dos algoritmos FIFO, Optimal e Clock/Second-Chance.

- Modos de Alocação: Possibilidade de alternar entre o modo Global (pool único de frames para todos os processos) e Local (frames fixos por processo).

- Visualização: Exibição detalhada da tabela de frames, destacando hits, faltas e substituições de páginas.

- Métricas: Cálculo da taxa de falhas de página ao final da simulação.

## Linguagem e Interface

O projeto foi desenvolvido em C++ com uma interface via Terminal feito para rodar no Windows

## Dependências e Bibliotecas

O projeto utiliza apenas bibliotecas padrão do C++ (parte da STL). As bibliotecas são:

- iostream: Para entrada e saída de dados.

- vector: Para gerenciar a sequência de acessos e a tabela de frames.

- string e <sstream>: Para manipulação e análise da entrada do usuário.

- queue: Para a implementação do algoritmo FIFO.

- thread e chrono: Para controlar o tempo de exibição no modo automático.

- climits: Para obter o valor máximo de um tipo inteiro, usado no algoritmo Optimal.

- iomanip: Para formatação da saída numérica.

## Instruções de Compilação e Execução

Para compilar o projeto, precisará de um compilador C++ (como TDM GCC ou clang++):

1. Compile os arquivos-fonte (É recomendável usar a flag -std=c++17 ou superior p/ garantir compatibilidade total com as bibliotecas):

   g++ -std=c++17 main.cpp simulacao.cpp util.cpp -o simulador

3. Execute o programa:

   simulador.exe

## Decisões de Projeto

- Modularidade: O código foi dividido em arquivos de cabeçalho (.h) e de implementação (.cpp) para promover a reutilização e organização.

  - simulacao.h e simulacao.cpp: Contêm a lógica central de simulação e os algoritmos de substituição.

  - util.h e util.cpp: Gerenciam a interface de usuário (limpar tela, colorir texto, imprimir frames) para manter a lógica de simulação limpa.

  - main.cpp: Responsável pela interação com o usuário, menus e inicialização da simulação.

- Eficiência: A implementação do algoritmo Optimal foi otimizada para buscar o próximo uso de cada página de forma eficiente. O algoritmo Clock foi implementado com um ponteiro único que avança no pool de frames, replicando o comportamento de um relógio.

## Screenshots do Simulador

- Menu inicial:
<img width="743" height="456" alt="image" src="https://github.com/user-attachments/assets/70e54b5f-c089-46ac-9b8b-6c99eeb8b5b8" />

- Menu com dados inseridos:
<img width="743" height="456" alt="image" src="https://github.com/user-attachments/assets/b3a32ff4-e790-4e9d-8a8e-718b4c505229" />

- Simulação
<img width="743" height="456" alt="image" src="https://github.com/user-attachments/assets/0624c083-93b6-438a-8fb3-4150987848fa" />

- Simulação finalizada
<img width="743" height="456" alt="image" src="https://github.com/user-attachments/assets/b1d3cbc4-e515-490c-827f-cda68fb5a425" />
