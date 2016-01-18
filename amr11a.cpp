#include <stdio.h>

int main() {
  int t;
  scanf("%d", &t);

  while (t--) {
    int r, c;
    scanf("%d %d", &r, &c);

    int m[r][c];
    for (int i = 0; i < r; i++)
      for (int j = 0; j < c; j++)
        scanf("%d", &m[i][j]);

  }

  return 0;
}