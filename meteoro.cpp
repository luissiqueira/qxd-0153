#include <stdio.h>int main() {  int x1, y1, x2, y2, xm, ym, n, cont, t = 1;  while (1) {    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);    if (x1 == x2 && y1 == y2 && x1 == y1 && y2 == 0) break;    scanf("%d", &n);    cont = 0;    for (int i = 0; i < n; ++i) {      scanf("%d %d", &xm, &ym);      if (xm >= x1 && ym <= y1 && xm <= x2 && ym >= y2)        cont++;    }    printf("Teste %d\n", t++);    printf("%d\n\n", cont);  }}