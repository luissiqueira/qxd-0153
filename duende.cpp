// http://br.spoj.com/problems/DUENDE/
// 2608. Duende Perdido
// Luis Siqueira - 338975
// Desafios de programação

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int map[12][12];
int init_x = 0, init_y = 0;

void show(int matriz[][12], int n, int m) {
  int l, c;

  for (l = 0; l <= n + 1; l++) {
    for (c = 0; c <= m + 1; c++) {
      printf("%d ", matriz[l][c]);
    }
    printf("\n");
  }

  printf("\n");
}

void init_map(int matriz[][12], int n, int m) {
  int i, j;
  char value[2];

  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      scanf("%s", value);
      int ci = atoi(value);
      matriz[i][j] = ci;
      if (ci == 3) {
        init_x = i;
        init_y = j;
      }
    }
  }

  for (i = 0; i <= n + 1; i++) {
    matriz[0][i] = 2;
    matriz[n + 1][i] = 2;

    matriz[i][0] = 2;
    matriz[i][m + 1] = 2;
  }
}

int find_out(int matriz[][12], int n, int m) {
  int i, j;

  int aux[n + 2][m + 2];
  for (i = 0; i <= n + 1; i++) {
    for (j = 0; j <= m + 1; j++) {
      aux[i][j] = 0;
    }
  }

  int mx[] = {-1, 0, 0, 1};
  int my[] = {0, -1, 1, 0};


}

int main() {
  int m, n;
  scanf("%d %d", &n, &m);

  init_map(map, n, m);
  show(map, n, m);

  return 0;
}