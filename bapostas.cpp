#include<stdio.h>

int main() {
  int n;

  while (scanf("%d", &n) && n > 0) {
    int v[n];
    for (int i = 0; i < n; i++) scanf("%d", &v[i]);
    int mt = -1, ma = 0;
    for (int i = 0; i < n; i++) {
      ma += v[i];
      if (ma < 0) { ma = 0; }
      if (ma > mt) { mt = ma; }
    }

    if (mt > 0) {
      printf("The maximum winning streak is %d.\n", mt);
    } else {
      printf("Losing streak.\n");
    }
  }

  return 0;
}