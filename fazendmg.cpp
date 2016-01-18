#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define VAZIO 0
#define TERRENO 1
#define BORDA 2

int mx[] = {-1, 0, 1, 0};
int my[] = {0, -1, 0, 1};
int a[1502][1502];

int main() {
  int n;

  while(scanf("%d", &n) != EOF && n != 0) {
    int area = 0;
    long long int comprimento = 0;

    for (int i = 0; i < 1502; i++)
      for (int j = 0; j < 1502; j++)
        a[i][j] = VAZIO;

    while (n--) {
      int x, y, l, c;
      scanf("%d %d %d %d", &x, &y, &l, &c);

      x++;
      y++;
      l--;
      c--;

      for (int i = x; i <= x + l; i++) {
        for (int j = y; j <= y + c; j++) {
          if (a[i][j] != TERRENO) {
            area++;
            a[i][j] = TERRENO;
          }
        }
      }
    }

    for (int i = 1; i < 1501; i++)
      for (int j = 1; j < 1501; j++) {
        if (a[i][j] == TERRENO) {
          for (int m = 0; m < 4; m++) {
            int nx = mx[m] + i;
            int ny = my[m] + j;

            if (a[nx][ny] == VAZIO) comprimento++;
          }
        }
      }

    printf("%d %lld\n", area, comprimento);
  }
}