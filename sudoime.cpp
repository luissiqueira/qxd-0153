// http://br.spoj.com/problems/SUDOIME/
// 1763. Sudoku
// Luis Siqueira - 338975
// Desafios de programação

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int matriz[9][9];

void read(int matriz[][9]) {
  int i, j;
  char value[2];

  for (i = 0; i < 9; i++) {
    for (j = 0; j < 9; j++) {
      scanf("%s", value);
      matriz[i][j] = atoi(value) - 1;
    }
  }
}

int validate_region(int matriz[][9], int l, int c) {
  int n[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

  int i, j;
  for (i = l; i < l + 3; i++) {
    for (j = c; j < c + 3; j++) {
      int v = matriz[i][j];
      if (n[v] != 0) {
        return 0;
      }
      n[v] = 1;
    }
  }

  return 1;
}

int is_valid(int matriz[][9]) {
  int i, p;

  int x[] = {0, 3, 6};
  for (i = 0; i < 3; i++) {
    for (p = 0; p < 3; p++) {
      if (validate_region(matriz, x[i], x[p]) == 0) {
        return 0;
      }
    }
  }

  for (p = 0; p < 9; p++) {
    int nl[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    int nc[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

    for (i = 0; i < 9; i++) {
      int c = matriz[i][p];
      if (nc[c] != 0) {
        return 0;
      }
      nc[c] = 1;

      int l = matriz[p][i];
      if (nl[l] != 0) {
        return 0;
      }
      nl[l] = 1;
    }
  }
  return 1;
}

int main() {
  int tk, loop = 0;
  scanf("%d", &tk);

  while (loop++ < tk) {
    read(matriz);
    int valid = is_valid(matriz);
    printf("Instancia %d\n", loop);
    printf("%s\n\n", valid == 1 ? "SIM" : "NAO");
  }

  return 0;
}