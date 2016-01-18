#include<stdio.h>
#include<algorithm>
#include<set>
#include<bitset>

#define MAX 100000

std::bitset<100001> bs;

long long int mdc(long long int a, long long int b) {
  while (b > 0) {
    long long int r = a % b;
    a = b;
    b = r;
  }
  return a;
}

long long int mmc(long long int a, long long int b) {
  return (a * b) / mdc(a, b);
}

int main() {
  int n, t;

  while (scanf("%d %d", &n, &t) != EOF && n != 0 && t != 0) {
    bs.reset();

    long long int r;
    scanf("%lld", &r);

    bs.set(r, 1);
    int tr = 1;

    for (long long int i = 1; i < n; i++) {
      long long int x;
      scanf("%lld", &x);
      if (t % x != 0) { tr = 0; }
      if (tr == 1) {
        bs.set(x, 1);
        r = mmc(r, x);
      }
    }

    long long int v = -1;
    if (tr == 1) {
      for (int i = 2; i <= t / 2; i++) {
        if (t % i == 0) {
          if (mmc(r, i) == t && !bs.test(i)) {
            v = i;
            break;
          }
        }
      }

      if (v == -1) {
        if (mmc(r, t) == t && !bs.test(t)) {
          v = t;
        }
      }
    }

    if (v != -1) {
      printf("%lld\n", v);
    } else {
      printf("impossivel\n");
    }
  }

  return 0;
}









