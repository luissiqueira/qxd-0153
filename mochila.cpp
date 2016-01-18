#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include <map>

using namespace std;

typedef pair<int, int> ii;
map<ii, int> mochila;

int pesos[] = {20, 20, 30, 30};
int valores[] = {20, 30, 20, 40};

int max(int a, int b) { return a > b ? a : b; }

int count1 = 0;
int count2 = 0;

int m(int n, int w) {
  count1++;

  if (n == -1) return 0;

  if (pesos[n] <= w) {
    return max(m(n - 1, w), m(n, w - pesos[n]) + valores[n]);
  } else {
    return m(n - 1, w);
  }
}

int m_2(int n, int w) {
  count2++;

  if (n == -1) return 0;

  int value = mochila[make_pair(n, w)];

  if (value > 0) return value;

  if (pesos[n] <= w) {
    value = max(m_2(n - 1, w), m_2(n, w - pesos[n]) + valores[n]);
    mochila[make_pair(n, w)] = value;
  } else {
    value = m_2(n - 1, w);
  }

  return value;
}

int main() {
  int v = m(3, 60);
  printf("Valor maximo: %d - Loops sem memoria: %d\n", v, count1);

  v = m_2(3, 60);
  printf("Valor maximo: %d - Loops com memoria: %d\n", v, count2);

  printf("Loops ganhos: %d\n", count1 - count2);
  return 0;
}