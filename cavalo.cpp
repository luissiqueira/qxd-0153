#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TAB_SIZE 6

int tab[TAB_SIZE][TAB_SIZE];

int mx[] = {1, -1, -1, 1, -2, 2, -2, 2};
int my[] = {-2, -2, 2, 2, -1, -1, 1, 1};

int bingo = 0;
int count = 0;

void init() {
  int i, j;
  for (i = 0; i < TAB_SIZE; i++) {
    for (j = 0; j < TAB_SIZE; j++) {
      tab[i][j] = 0;
    }
  }
}

void show_tab() {
  int i, j;
  for (i = 0; i < TAB_SIZE; i++) {
    for (j = 0; j < TAB_SIZE; j++) {
      printf("%2d ", tab[i][j]);
    }
    printf("\n");
  }
}

void walk(int x, int y, int m) {
  count++;

  if (m > TAB_SIZE * TAB_SIZE) {
    bingo = 1;
    show_tab();
    return;
  }

  if (x < 0 || x >= TAB_SIZE || y < 0 || y >= TAB_SIZE) return;

  if (tab[x][y] != 0) return;

  tab[x][y] = m;
  int i, j;
  for (i = 0; i < 8; i++) {
    walk(x + mx[i], y + my[i], m + 1);
    if (bingo) {
      return;
    }
  }
  tab[x][y] = 0;


}

int main() {
  init();
  walk(4, 3, 1);
  printf("Total de movimentos: %d\n", count);
  return 0;
}