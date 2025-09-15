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
