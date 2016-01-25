#include <stdio.h>
#include <cmath>

int main() {
  int total_bac, melhor_bac;
  double maior = 0.0;

  scanf("%d", &total_bac);

  for (int i = 0; i < total_bac; ++i) {
    int c, d;

    scanf("%d %d", &c, &d);
    double capacidade = d * log(c);

    if (capacidade > maior) {
      maior = capacidade;
      melhor_bac = i;
    }
  }

  printf("%d", melhor_bac);
}