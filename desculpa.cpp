#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<map>

using namespace std;

typedef pair<int, int> ii;
map<ii, int> cartao;

#define MAX_VALUE 1000

int pesos[MAX_VALUE];
int valores[MAX_VALUE];

int max(int a, int b) { return a > b ? a : b; }


int m(int n, int w) {
  if (n == -1) return 0;

  int value = cartao[make_pair(n, w)];

  if (value > 0) return value;

  if (pesos[n] <= w) {
    value = max(m(n - 1, w), m(n - 1, w - pesos[n]) + valores[n]);
    cartao[make_pair(n, w)] = value;
  } else {
    value = m(n - 1, w);
  }

  return value;
}

int main() {
  int c, f;
  int loop = 0;

  while (scanf("%d %d", &c, &f)) {
    if (c == 0 || f == 0) {
      break;
    }

    int i;
    for (i = 0; i < f; i++) {
      int n, d;
      scanf("%d %d", &n, &d);
      pesos[i] = n;
      valores[i] = d;
    }

    printf("Teste %d\n", ++loop);
    printf("%d\n\n", m(f, c));

    cartao.clear();
  }

  return 0;
}