#include<stdio.h>

void euclidianoEstendido(int a, int b, int *alpha, int *beta, int *mdc) {
  int x[2] = {1, 0};
  int y[2] = {0, 1};

  /* Enquanto o resto da divisão de a por b não for zero, eu continuo o algoritmo. */
  while (a % b != 0) {
    int quociente = a / b;

    /* Atualizando os valores de a e b. */
    int temp = a;
    a = b;
    b = temp % b;

    /* Atualizando os valores de x e y. */
    int X = x[0] - (x[1] * quociente);
    int Y = y[0] - (y[1] * quociente);

    x[0] = x[1];
    x[1] = X;
    y[0] = y[1];
    y[1] = Y;

    printf("r: %d u: %d v: %d\n", b, x[1], y[1]);
  }

  *mdc = b;
  *alpha = x[1];
  *beta = y[1];
}

int main() {
  int a, b;
  a = 8;
  b = 5;
  int alpha, beta, mdc;

  euclidianoEstendido(a, b, &alpha, &beta, &mdc);
}