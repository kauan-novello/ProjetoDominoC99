#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Estrutura das peças de dominó
struct Pecas {
    int id;
    int left;
    int rigth;
};

struct Player {
    struct Pecas pecas[6];
}p1,p2,p3,p4;

struct Dorme {
    struct Pecas pecas[4];
}dorme;


int main() {
    
    srand(time(NULL)); // Inicializa 

    struct Pecas pecas[] = {
        {1, 0,0},     {2, 0,1},     {3, 0,2},     {4, 0,3},     {5, 0,4},     {6, 0,5},    {7, 0,6},
        {8, 1,1},     {9, 1,2},     {10, 1,3},    {11, 1,4},    {12, 1,5},    {13, 1,6},
        {14, 2,2},    {15, 2,3},    {16, 2,4},    {17, 2,5},    {18, 2,6},
        {19, 3,3},    {20, 3,4},    {21, 3,5},    {22, 3,6},
        {23, 4,4},    {24, 4,5},    {25, 4,6},
        {26, 5,5},    {27, 5,6},
        {28, 6,6}
    };

    
    int tamanho = 28; //int tamanho = sizeof(pecas) / sizeof(pecas[0]);

    // Embaralha as peças de dominó
    for (int i = 0; i < tamanho - 1; i++) {
        
        int j = i + rand() % (tamanho - i); // faz com que o numero aleatório esteja entre 0 e 27 
    
        struct Pecas temp = pecas[i];
        pecas[i] = pecas[j];
        pecas[j] = temp;
    }

    // Imprime as peças de dominó embaralhadas
    // for (int i = 0; i < tamanho; i++) {
    //     printf("ID: %d, Nome: %s\n", pecas[i].id, pecas[i].left, pecas[i].rigth);
    // }

    //Distribuir peça dos jogadores e do dorme

    printf("Pecas do jogador 1 (p1):\n\n");
    for (int i = 0; i < 6; i++) {
        p1.pecas[i] = pecas[i];
        printf("ID: %02d, Peca: [%d|%d]\n", p1.pecas[i].id, p1.pecas[i].left, p1.pecas[i].rigth);
    }
    printf("\n");

    printf("Pecas do jogador 2 (p2):\n\n");
    for (int i = 6; i < 12; i++) {
        p2.pecas[i] = pecas[i];
        printf("ID: %02d, Peca: [%d|%d]\n", p2.pecas[i].id, p2.pecas[i].left, p2.pecas[i].rigth);
    }
    printf("\n");
    
    printf("Pecas do jogador 3 (p3):\n\n");
    for (int i = 12; i < 18; i++) {
        p3.pecas[i] = pecas[i];
        printf("ID: %02d, Peca: [%d|%d]\n", p3.pecas[i].id, p3.pecas[i].left, p3.pecas[i].rigth);
    }
    printf("\n");

    printf("Pecas do jogador 4 (p4):\n\n");
    for (int i = 18; i < 24; i++) {
        p4.pecas[i] = pecas[i];
        printf("ID: %02d, Peca: [%d|%d]\n", p4.pecas[i].id, p4.pecas[i].left, p4.pecas[i].rigth);
    }
    printf("\n");
    
    printf("Pecas do Dorme:\n\n");
    for (int i = 24; i < 28; i++) {
        dorme.pecas[i] = pecas[i];
        printf("ID: %02d, Peca: [%d|%d]\n", dorme.pecas[i].id, dorme.pecas[i].left, dorme.pecas[i].rigth);
    }
    printf("\n\n");

     int rodada = 1;

    printf("Pressione alguma tecla para comecar");
    char tecla;
    getchar(); 

    while (rodada--)
    {

        system("cls");
        printf("Pecas do jogador 1 (p1):\n\n");
        for (int i = 0; i < 6; i++) {
            p1.pecas[i] = pecas[i];
            printf("ID: %02d, Peca: [%d|%d]\n", p1.pecas[i].id, p1.pecas[i].left, p1.pecas[i].rigth);
        }
        printf("\n");

        printf("Faca sua jogada");
        getchar(); 

        //transformar jogadas em função
        
        break;
    }
    
    // pra começar o jogo na rodada 1 o player que tiver o 6/6 começa, caso esteja no dorme, vai para o 5/5 e assim sucessivamente...
    // faça a opção de jogada e remova a peça quando jogada
    
    

    return 0;
}
