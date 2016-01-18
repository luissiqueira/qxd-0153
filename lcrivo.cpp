#include<bitset>
#include<stdio.h>

using namespace std;

bitset<1000001> bs;

void init() {
  bs.set();
  bs.set(0, 0);
  bs.set(1, 0);
  for (int i = 2; i <= 1000; i++) {
    for (int j = i*i; j <= 1000000; j += i) {
      bs.set(j, 0);
    }
  }
}

int main() {
  init();

  int t = 0;
  for (int i = 1; i < 1000001; i++)
    if (bs.test(i)) t++;

  printf("%d ", t);
  printf("%d ", static_cast<int>(bs.count()));
  return 0;
}