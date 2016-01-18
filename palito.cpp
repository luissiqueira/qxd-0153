#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MODO_MIN 0
#define MODO_MAX 1

#define INI_VALUE 15
#define MAX_VALUE 3

int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }

int jogo(int modo, int valor) {
  if (valor <= MAX_VALUE) {
    if (modo == MODO_MIN) return 0;
    return 1;
  }

  int r = modo == MODO_MIN ? 1 : 0;
  int i;

  for (i = 1; i <= MAX_VALUE; i++) {
    if (modo == MODO_MIN) {
      r = min(r, jogo(MODO_MAX, valor - i));
    } else {
      r = max(r, jogo(MODO_MIN, valor - i));
    }
  }

  return r;
}

int main() {
  if (jogo(MODO_MAX, INI_VALUE) == 1) {
    printf("Ganha\n");
  } else {
    printf("Perde\n");
  }

  return 0;
}