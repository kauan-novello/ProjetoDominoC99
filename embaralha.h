#ifndef EMBARALHA_H
#define EMBARALHA_H
struct Pecas {
  int id;
  int left;
  int right;
  struct Pecas *prox;
  struct Pecas *ant;
};
void embaralharPecas(struct Pecas listaPecas[]);
#endif // embaralha_H
