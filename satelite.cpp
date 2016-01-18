// http://olimpiada.ic.unicamp.br/passadas/OBI1999/pdf/provas/ProvaOBI1999.pdf
// Imagens de Satélite
// Luis Siqueira - 338975
// Desafios de programação

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char matriz[82][52];

void show(char matriz[][52], int m, int n) {
  int l;

  for (l = 0; l <= m + 1; l++) {
    printf("%s\n", matriz[l]);
  }

  printf("\n");
}

void init_matriz(char matriz[][52], int m, int n) {
  int i;

  for (i = 1; i <= m; i++) {
    scanf("%s", &matriz[i][1]);
  }

  for (i = 0; i <= m + 1; i++) {
    matriz[0][i] = '0';
    matriz[m + 1][i] = '0';

    matriz[i][0] = '0';
    matriz[i][n + 1] = '0';
  }
}

void destroy(char matriz[][52], int l, int c) {
  int x[] = {-1, -1, -1, 0, 0, 1, 1, 1};
  int y[] = {-1, 0, 1, -1, 1, -1, 0, 1};

  if (matriz[l][c] != '0') {
    matriz[l][c] = '0';

    int i, j;
    for (i = 0; i < 8; i++) {
      for (j = 0; j < 8; j++) {
        if (matriz[l + x[i]][c + y[j]] != '0') {
          destroy(matriz, l + x[i], c + y[j]);
        }
      }
    }
  }
}

int count(char matriz[][52], int m, int n) {
  int l, c;
  int total = 0;

  for (l = 1; l <= m; l++) {
    for (c = 1; c <= n; c++) {
      if (matriz[l][c] != '0') {
        ++total;
        destroy(matriz, l, c);
      }
    }
  }

  return total;
}

int main() {
  int m, n;
  int loop = 0;
  scanf("%d %d", &m, &n);

  if (m != 0 && n != 0) {
    do {
      init_matriz(matriz, m, n);

      printf("Teste %d\n", ++loop);
      printf("Numero de contrucoes: %d\n\n", count(matriz, m, n));

      scanf("%d %d", &m, &n);
    } while (m != 0 && n != 0);
  }
  return 0;
}