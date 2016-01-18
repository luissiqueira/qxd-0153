#include<stdio.h>
#include<math.h>
#include<map>
#include<vector>

typedef long long int bigint;
typedef std::vector<bigint> vb;
typedef std::map<bigint, int> bi;

int magic(int n) {
  if (n < 2) return 0;
  int res = n;
  int limite = sqrt(n) + 1;
  for (int p = 2; p <= limite; p++) {
    if (n % p == 0) res = res / p * (p - 1);
    while (n % p == 0) n /= p;
    limite = sqrt(n) + 1;
  }

  if (n > 1) {
    res = res / n * (n - 1);
  }
  return res / 2;
}

int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    int p = magic(n);
    printf("%d\n", p);
  }
  return 0;
}