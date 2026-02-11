#include <stdio.h>
#include <string.h>

#define N 8
#define INF 1e9f

int main () {
    //leitura do arq de antenas
    FILE *arquivo;
    int qAntenas, ant1, ant2;
    float dist;

    float grafo[N+1][N+1];

    arquivo = fopen("antenas.txt","r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    fscanf(arquivo, "%d", &qAntenas);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            grafo[i][j] = (i == j) ? 0.0f : INF;
        }
    }

    while (fscanf(arquivo, "%d %d %f", &ant1, &ant2, &dist) == 3) {
        if (dist < grafo[ant1][ant2]) {
            grafo[ant1][ant2] = dist;
            grafo[ant2][ant1] = dist;
        }
    }

    fclose(arquivo);

    //origem fixa
    int origem = 3;

    int destino;
    char mensagem[256];

    printf("## SISTEMA DE SEGURANÇA OFF-GRID DE MENSAGENS ##\n");
    printf("[Voce é a antena %d]\n", origem);
    printf("---------------------------------------------------\n");

    printf("Escolha a antena de destino (1 a %d): ", N);
    scanf("%d", &destino);

    if (destino < 1 || destino > N || destino == origem) {
        printf("Destino invalido!\n");
        return 0;
    }

    getchar();

    printf("Digite a mensagem: ");
    fgets(mensagem, sizeof(mensagem), stdin);
    mensagem[strcspn(mensagem, "\n")] = '\0';

    // logica djikstra da origem para o destino escolhido
    float d[N+1]; 
    int visitado[N+1];
    int anterior[N+1];

    for (int i = 1; i <= N; i++) {
        d[i] = INF;
        visitado[i] = 0;
        anterior[i] = -1;
    }
    d[origem] = 0.0f; //distancia na posicao origem = 3

    for (int k = 1; k <= N; k++) {
        int u = -1; //vert. com menor dist a ser processado
        float melhor = INF; //menor distancia

        for (int i = 1; i <= N; i++) {
            if (!visitado[i] && d[i] < melhor) {
                melhor = d[i]; // atualiza a menor distancia
                u = i; // guarda o vertice de menor distancia desde a origem
            }
        }

        if (u == -1) break; // nenhum vertice alcancavel
        if (u == destino) break; // chegou ao final
        visitado[u] = 1; // no ja visitado

        //relaxa as arestas e continua
        for (int v = 1; v <= N; v++) {
            if (!visitado[v] && grafo[u][v] < INF) { //se v ainda nao foi visitado
                float nd = d[u] + grafo[u][v];
                if (nd < d[v]) {
                    d[v] = nd;
                    anterior[v] = u;
                }
            }
        }
    }

    if (d[destino] >= INF) {
        printf("Sem rota disponível até a antena %d.\n", destino);
        return 0;
    }

    int rota[N+1];
    int tam = 0;
    int atual = destino;

    while (atual != -1) {
        rota[tam++] = atual;
        if (atual == origem) break;
        atual = anterior[atual];
    }

    printf("\n>> Enviando mensagem pela menor rota: ");
    for (int i = tam - 1; i >= 0; i--) {
        printf("%d -", rota[i]);
        if (i > 0) printf(" ");
    }
    printf("\n");

    printf(">> Mensagem enviada: %s\n", mensagem);

    return 0;
}
