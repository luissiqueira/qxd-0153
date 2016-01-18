// http://br.spoj.com/problems/CHOCPJ09/
// 11629. Competiçăo de chocolate
// Luis Siqueira - 338975
// Desafios de programação

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
  int m, n;
  scanf("%d %d", &n, &m);
  printf(n % (m + 1) != 0 ? "Paula" : "Carlos");
  return 0;
}