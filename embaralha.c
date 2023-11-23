
#include "embaralha.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void embaralharPecas(struct Pecas listaPecas[]) {
{

    int tamanho = 28; // int tamanho = sizeof(pecas) / sizeof(pecas[0]);

    for (int i = 0; i < tamanho - 1; i++)
    {

        int j = i + rand() % (tamanho - i); // faz com que o numero aleatório esteja entre 0 e 27
        /*
            int j = i + rand() % (tamanho - i);
            Isso gera um número aleatório j tal que i <= j < tamanho.
            O operador % calcula o resto da divisão,
            e rand() retorna um número pseudoaleatório.

            Portanto, rand() % (tamanho - i) gera um número entre 0 e (tamanho - i -
           1), e somando i garante que j esteja dentro da faixa desejada.

            O algoritmo implementado neste código utiliza a técnica conhecida como
           "Fisher-Yates Shuffle". Essa técnica é projetada para garantir que não
           ocorram repetições durante o embaralhamento.

            A lógica por trás disso é que, em cada iteração do loop,
            uma peça é trocada por outra posição aleatória no array.
            Como o número aleatório j é gerado de forma única em cada iteração
            e é garantido que i <= j < tamanho, uma peça específica nunca será
           trocada duas vezes. Isso evita repetições e assegura que todas as peças
           permaneçam em posições únicas após o embaralhamento.

        */
        struct Pecas temp = listaPecas[i];
        listaPecas[i] = listaPecas[j];
        listaPecas[j] = temp;
    }
  }
   }
