#include<stdio.h>
#include<cmath>

int c_primo(int n) {
  int i = 2;
  int limite = (int) sqrt(n);
  int t_primos = 0;

  while (i <= limite) {
    if (n % i == 0) t_primos++;
    while (n % i == 0) n /= i;
    limite = (int) sqrt(n);
    i++;
  }

  if (n != 1) t_primos++;
  return t_primos;
}

int main() {
  int n;
  while (scanf("%d", &n) != EOF && n != 0) {
    printf("%d : %d\n", n, c_primo(n));
  }
  return 0;
}