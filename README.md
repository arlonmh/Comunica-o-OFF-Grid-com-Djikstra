
***COMUNICAÇÃO OFF-GRID COM DIJKSTRA (C)*** \
DESCRIÇÃO GERAL

* Este projeto implementa o algoritmo de Dijkstra em linguagem C
para calcular o menor caminho (menor custo) em um grafo
ponderado.

O grafo representa uma rede de comunicação OFF-Grid, onde:
* Cada vértice representa uma antena.
* Cada aresta representa uma conexão entre antenas.
* O peso da aresta indica a distância ou custo da comunicação

Os dados do grafo são lidos a partir do arquivo "antenas.txt",
que deve estar localizado na mesma pasta do executável.

ARQUIVOS DO PROJETO
* main.c
Arquivo principal contendo a implementação do algoritmo de
Dijkstra e toda a lógica do programa.

* antenas.txt
Arquivo de entrada contendo os dados do grafo (antenas,
conexões e pesos).

COMO EXECUTAR NO LINUX (Ubuntu, Debian, Zorin, etc.)

* Clone o repositório: git clone https://github.com/arlonmh/Comunica-o-OFF-Grid-com-Djikstra.git
* Entre na pasta do projeto: cd Comunica-o-OFF-Grid-com-Djikstra
* Compile o programa: gcc main.c -o main
* Execute o programa: ./main

OBSERVAÇÃO:
O arquivo "antenas.txt" deve permanecer na mesma pasta do
executável durante a execução.

COMO EXECUTAR NO WINDOWS
OPÇÃO 1 - MSYS2 (RECOMENDADO)
* Instale o MSYS2: https://www.msys2.org/
* Abra o terminal "MSYS2 UCRT64" ou "MINGW64".
* Instale o compilador GCC: pacman -S --needed mingw-w64-ucrt-x86_64-gcc
* Clone o repositório: git clone https://github.com/arlonmh/Comunica-o-OFF-Grid-com-Djikstra.git
* Entre na pasta do projeto: cd Comunica-o-OFF-Grid-com-Djikstra
* Compile o programa: gcc main.c -o main.exe
* Execute: ./main.exe

OPÇÃO 2 - MinGW-w64
* Instale o MinGW-w64 ou w64devkit e garanta que o GCC esteja
configurado corretamente no PATH do sistema.
* Abra o Prompt de Comando ou PowerShell.
* Navegue até a pasta do projeto (onde estão main.c e antenas.txt).
* Compile o programa: gcc main.c -o main.exe
* Execute: main.exe

OBSERVAÇÕES IMPORTANTES

O arquivo "antenas.txt" deve estar sempre na mesma pasta do
executável.

O programa utiliza caminho relativo para leitura do arquivo,
garantindo compatibilidade após o clone do repositório.
