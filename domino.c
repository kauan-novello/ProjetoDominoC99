
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Pecas {
  int id; // usado para fazer verificações de forma mais curta no código
  int left;
  int right;
  struct Pecas *prox; // Add these pointers to your struct
  struct Pecas *ant;
};
struct Player {
  struct Pecas pecas[6];
} p1, p2, p3, p4;

struct Dorme {
  struct Pecas pecas[4];
} dorme;

struct Pecas listaPecas[] = {
    {1, 0, 0},  {2, 0, 1},  {3, 0, 2},  {4, 0, 3},  {5, 0, 4},  {6, 0, 5},
    {7, 0, 6},  {8, 1, 1},  {9, 1, 2},  {10, 1, 3}, {11, 1, 4}, {12, 1, 5},
    {13, 1, 6}, {14, 2, 2}, {15, 2, 3}, {16, 2, 4}, {17, 2, 5}, {18, 2, 6},
    {19, 3, 3}, {20, 3, 4}, {21, 3, 5}, {22, 3, 6}, {23, 4, 4}, {24, 4, 5},
    {25, 4, 6}, {26, 5, 5}, {27, 5, 6}, {28, 6, 6}};

// Área de Chamada a Funções

void embaralharPecas();
void mostrarPecas();
int verificarQuemComeca();
void inserirNaLista(struct Pecas **head, struct Pecas **tail,
                    struct Pecas pecas[], int id);

void freelist(struct Pecas **head);
int jogadaPlayer(int player, struct Pecas **head, struct Pecas **tail);

int main() {
  struct Pecas *head = NULL;
  struct Pecas *tail = NULL;
  srand(time(NULL));

  embaralharPecas();
  mostrarPecas();

  printf("Pressione alguma tecla para comecar  ");
  getchar();

  /*
      defini 72 como o número maximo de jogadas possiveis, considerando os
     toques, seguindo a lógica de:

      1000 1000 1000 1000 1200
      0200 0200 0200 0230
      0030 0030 0030 0034
      0004 0004 0004 0004 0004

      considere 0 como toque e n como o jogador que jogou
      nesse caso mais utopico teriamos 72 jogadas

      jogada sendo considerado toques e peças a mesa

  */

  int playerInicial = verificarQuemComeca();

  printf("\n ok, iniciar");
  getchar();

  int jogadorCampeaoDa1rodada = 0;
  int rodada = -1;

  while (jogadorCampeaoDa1rodada == 0) {
    /*
        criar método para
        (após definido o player q ira começar)
        seguir uma ordem crescente,
        se o p1 começou segue 1,2,3,4
        se o p2 começou segue 2,3,4,1
        se o p3 começou segue 3,4,1,2
        se o p4 começou segue 4,1,2,3

        formula similar com for:

        for (int i = -1; i < ∞; i++){
            int vez = ((1 + i) % 4)+1;
            printf("%d\n", vez);
        }

    */

    int vez = ((playerInicial + rodada) % 4) + 1;
    jogadorCampeaoDa1rodada = jogadaPlayer(vez, &head, &tail);
    rodada++;

    /*
        Explicação para o trecho a cima,
        precisava achar alguma forma para que as jogadas fossem ordenadas de
       acordo com o num de players.

        Ex: se o p4 começou deveria se seguir a ordem p4, p1, p2 e p3, e voltar
       pra p4 e seguir até que o jogo acabasse; então criei a varaivel "rodada"
       sendo um inteiro q representa as rodadas, e a cada rodada ele vai
       incrementando a 1; e usei a fomrula (playerInicial + rodada) % 4 que é a
       quantidade de jogadores +1, rodada começando de -1;

        assim digamos que p4 comecesse, temos: vez = ((4 + (-1)) % 4) = 3 | 3 +
       1 = 4 na proxima temos: vez = ((4 + 0) % 4) = 0 | 0 + 1 = 1 na proxima
       temos: vez = ((4 + 1) % 4) = 1 | 1 + 1 = 2 na proxima temos: vez = ((4 +
       2) % 4) = 2 | 2 + 1 = 3 na proxima temos: vez = ((4 + 3) % 4) = 3 | 3 + 1
       = 4 e então segue a ordem  4, 1, 2, 3,  4, 1, 2, 3,  4 ...
    */

    printf("Player %d e %d venceram essa rodada", jogadorCampeaoDa1rodada,
           jogadorCampeaoDa1rodada + 2); // anotar pontuação depois
  }

  return 0;
}

// Área de Descrição das Funções

void embaralharPecas() {

  int tamanho = 28; // int tamanho = sizeof(pecas) / sizeof(pecas[0]);

  for (int i = 0; i < tamanho - 1; i++) {

    int j =
        i + rand() % (tamanho -
                      i); // faz com que o numero aleatório esteja entre 0 e 27
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

void mostrarPecas() {
  printf("Pecas do jogador 1 (p1):\n\n");
  for (int i = 0; i < 6; i++) {
    p1.pecas[i] = listaPecas[i];
    printf("ID: %02d, Peca: [%d|%d]\n", p1.pecas[i].id, p1.pecas[i].left,
           p1.pecas[i].right);
  }
  printf("\n");

  printf("Pecas do jogador 2 (p2):\n\n");
  for (int i = 6; i < 12; i++) {
    p2.pecas[i - 6] = listaPecas[i];
    printf("ID: %02d, Peca: [%d|%d]\n", p2.pecas[i - 6].id,
           p2.pecas[i - 6].left, p2.pecas[i - 6].right);
  }
  printf("\n");

  printf("Pecas do jogador 3 (p3):\n\n");
  for (int i = 12; i < 18; i++) {
    p3.pecas[i - 12] = listaPecas[i];
    printf("ID: %02d, Peca: [%d|%d]\n", p3.pecas[i - 12].id,
           p3.pecas[i - 12].left, p3.pecas[i - 12].right);
  }
  printf("\n");

  printf("Pecas do jogador 4 (p4):\n\n");
  for (int i = 18; i < 24; i++) {
    p4.pecas[i - 18] = listaPecas[i];
    printf("ID: %02d, Peca: [%d|%d]\n", p4.pecas[i - 18].id,
           p4.pecas[i - 18].left, p4.pecas[i - 18].right);
  }
  printf("\n");

  printf("Pecas do Dorme:\n\n");
  for (int i = 24; i < 28; i++) {
    dorme.pecas[i - 24] = listaPecas[i];
    printf("ID: %02d, Peca: [%d|%d]\n", dorme.pecas[i - 24].id,
           dorme.pecas[i - 24].left, dorme.pecas[i - 24].right);
  }
  printf("\n\n");
}

int verificarQuemComeca() {
  /*
       função para saber quem será o primeiro jogador
       para saber quem começa verifica qual dos jogadores tem a peça de Id 28,
       caso esteja no dorme passa para a de Id 26,
       caso esteja no dorme passa para a de Id 23,
       caso esteja no dorme passa para a de Id 19,
       caso a 28, a 26, a 23 e a 19, estejam ambas no dorme,
       obrigatoriamente algum dos players tem que ter a 14
       e esse seria o player que começaria o jogo
  */

  int playerdavez;

  // Checa se algum do player tem a peça 28
  for (int i = 0; i < 6; i++) {
    if (p1.pecas[i].id == 28) {
      playerdavez = 1;
      break;
    } else if (p2.pecas[i].id == 28) {
      playerdavez = 2;
      break;
    } else if (p3.pecas[i].id == 28) {
      playerdavez = 3;
      break;
    } else if (p4.pecas[i].id == 28) {
      playerdavez = 4;
      break;
    }
  }
  // se ngm tiver a 28 checka a 26
  if (playerdavez == 0) {
    for (int i = 0; i < 6; i++) {
      if (p1.pecas[i].id == 26) {
        playerdavez = 1;
        break;
      } else if (p2.pecas[i].id == 26) {
        playerdavez = 2;
        break;
      } else if (p3.pecas[i].id == 26) {
        playerdavez = 3;
        break;
      } else if (p4.pecas[i].id == 26) {
        playerdavez = 4;
        break;
      }
    }
  }
  // se ngm tiver a 26 checka a 23
  if (playerdavez == 0) {
    for (int i = 0; i < 6; i++) {
      if (p1.pecas[i].id == 23) {
        playerdavez = 1;
        break;
      } else if (p2.pecas[i].id == 23) {
        playerdavez = 2;
        break;
      } else if (p3.pecas[i].id == 23) {
        playerdavez = 3;
        break;
      } else if (p4.pecas[i].id == 23) {
        playerdavez = 4;
        break;
      }
    }
  }
  // se ngm tiver a 23 checka a 19
  if (playerdavez == 0) {
    for (int i = 0; i < 6; i++) {
      if (p1.pecas[i].id == 19) {
        playerdavez = 1;
        break;
      } else if (p2.pecas[i].id == 19) {
        playerdavez = 2;
        break;
      } else if (p3.pecas[i].id == 19) {
        playerdavez = 3;
        break;
      } else if (p4.pecas[i].id == 19) {
        playerdavez = 4;
        break;
      }
    }
  }
  // se ngm tiver a 19 obrigatoriamente alguem tem que 14
  if (playerdavez == 0) {
    for (int i = 0; i < 6; i++) {
      if (p1.pecas[i].id == 14) {
        playerdavez = 1;
        break;
      } else if (p2.pecas[i].id == 14) {
        playerdavez = 2;
        break;
      } else if (p3.pecas[i].id == 14) {
        playerdavez = 3;
        break;
      } else if (p4.pecas[i].id == 14) {
        playerdavez = 4;
        break;
      }
    }
  }

  // definido o player

  printf("Player %d comeca o jogo!\n", playerdavez);

  return playerdavez;
}
void inserirNaLista(struct Pecas **head, struct Pecas **tail,
                    struct Pecas listaPecas[], int id) {
  struct Pecas *novoNo = (struct Pecas *)malloc(sizeof(struct Pecas));
  for (int i = 0; i < 28; i++) { // verifica qual é a peca a ser inserida
    if (listaPecas[i].id == id) {
      if (*head == NULL) {
        /* Se a lista está vazia, a função faz head e tail serem o no da nova
         * peca inserida*/
        novoNo->id = listaPecas[i].id;
        novoNo->left = listaPecas[i].left;
        novoNo->right = listaPecas[i].right;
        novoNo->prox = NULL;
        novoNo->ant = NULL;
        *head = novoNo;
        *tail = novoNo;

      } else {
        int unico = (*head == *tail);
        if (listaPecas[i].left == (*head)->left ||
            listaPecas[i].right ==
                (*head)
                    ->left) { // verifica caso a peça possa ser inserida no head
          novoNo->id = listaPecas[i].id;
          if (listaPecas[i].right == (*head)->left) {
            novoNo->left = listaPecas[i].left;
            novoNo->right = listaPecas[i].right;
            (*head)->prox = novoNo;
            novoNo->ant = *head;
            *head = novoNo;
            novoNo->prox = NULL;
          } else { // caso precise girar a peca
            novoNo->left = listaPecas[i].right;
            novoNo->right = listaPecas[i].left;
            (*head)->prox = novoNo;
            novoNo->ant = *head;
            *head = novoNo;
            novoNo->prox = NULL;
          } /* caso insira no head, a nova peça vira o head, e linka o novo no
               com o antigo head e visse versa */
        }
        if (!unico) { /* faz as mudanças apenas uma vez, já que a head e tail
                         representam o mesmo no quando apenas 1 foi inserido*/
          if (listaPecas[i].left == (*tail)->right ||
              listaPecas[i].right ==
                  (*tail)->right) { /* verifica caso a peça possa
                                    ser inserida no tail*/
            novoNo->id = listaPecas[i].id;
            if (listaPecas[i].left == (*tail)->right) {
              novoNo->left = listaPecas[i].left;
              novoNo->right = listaPecas[i].right;
              (*tail)->ant = novoNo;
              novoNo->prox = *tail;
              *tail = novoNo;
              novoNo->ant = NULL;
            } else { // caso precise girar a peca
              novoNo->left = listaPecas[i].right;
              novoNo->right = listaPecas[i].left;
              (*tail)->ant = novoNo;
              novoNo->prox = *tail;
              *tail = novoNo;
              novoNo->ant = NULL;
            }
          }
        }
      }
    }
  }
}

void freelist(struct Pecas **head) {
  struct Pecas *atual = *head;
  struct Pecas *temp = NULL;
  while (atual != NULL) {
    temp = atual;
    atual = atual->prox; /* move para o próximo nó*/
    free(temp);          /* libera o nó atual*/
  }
  *head = NULL; /* define o ponteiro head para NULL após a lista ser destruída*/
}

int jogadaPlayer(int player, struct Pecas **head, struct Pecas **tail) {

  printf("Vez do jogador %d:\n", player);

  printf("Suas pecas: \n");
  for (int i = 0; i < 6; i++) {
    if (player == 1) {
      printf("ID: %02d, Peca: [%d|%d]\n", p1.pecas[i].id, p1.pecas[i].left,
             p1.pecas[i].right);
    }
    if (player == 2) {
      printf("ID: %02d, Peca: [%d|%d]\n", p2.pecas[i].id, p2.pecas[i].left,
             p2.pecas[i].right);
    }
    if (player == 3) {
      printf("ID: %02d, Peca: [%d|%d]\n", p3.pecas[i].id, p3.pecas[i].left,
             p3.pecas[i].right);
    }
    if (player == 4) {
      printf("ID: %02d, Peca: [%d|%d]\n", p4.pecas[i].id, p4.pecas[i].left,
             p4.pecas[i].right);
    }
  }
  printf("\n Pecas na mesa: \n");

  printf("\nEscolha o Id da peca que deseja jogar: ");

  int idAtual = 0;
  scanf("%d", &idAtual);

  inserirNaLista(head, tail, listaPecas, idAtual);

  int ganhar = 0;

  if (idAtual == 0) {
    ganhar = player;
  }

  return ganhar;
}
