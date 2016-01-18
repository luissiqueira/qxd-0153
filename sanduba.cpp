// http://br.spoj.com/problems/SANDUBA/
// 4745. Sanduíche-íche-íche de atum
// Luis Siqueira - 338975
// Desafios de programação

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
  int t;

  scanf("%d", &t);

  while(t--) {
    int n;
    scanf("%d", &n);

    int s[n];
    int line = 0;
    long long sum = 0;

    for (int i = 0; i < n; i++) {
      scanf("%d", &s[i]);
      line += s[i];
    }

    for (int i = 0; i < n; i++) {
      sum += ((line % 1300031) * (s[i] % 1300031)) % 1300031;
      line -= s[i];

    }

    printf("%lld", sum % 1300031);
    printf("\n");
  }
}