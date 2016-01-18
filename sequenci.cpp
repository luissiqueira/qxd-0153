#include <stdio.h>

int main() {
  int t;
  int ct = 0;
  int soma[1001];

  while (scanf("%d", &t) != EOF && t) {
    for (int i = 0; i < 1001; i++) {
      soma[i] = 0;
    }

    printf("Case #%d:", ++ct);

    int ok = 1;
    int ele;
    int prev = 0;
    for (int i = 0; i < t; i++) {
      scanf("%d", &ele);
      printf(" %d", ele);

      if (soma[ele]) ok = 0;
      if (ele <= prev) ok = 0;

      prev = ele;

      for (int i = 1000; i >= 1 + ele; i--) {
        if (soma[i - ele]) soma[i] = 1;
      }
      soma[ele] = 1;
    }

    if (ok == 0) printf("\nThis is not an A-sequence.\n");
    else printf("\nThis is an A-sequence.\n");
  }

  return 0;
}