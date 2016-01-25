#include <stdio.h>
#include <cstring>
#include <queue>

#define MAX_VEND 1000

using namespace std;

int atendimentos[MAX_VEND];
int t_atendimentos[MAX_VEND];

int main() {
  queue<int> calls;
  int n, l;

  int menor = 31;

  scanf("%d %d", &n, &l);
  memset(atendimentos, -1, sizeof(atendimentos));
  memset(t_atendimentos, 0, sizeof(t_atendimentos));

  while (l--) {
    int time = 0;
    scanf("%d", &time);
    calls.push(time);
  }

  for (int i = 0; i < n && !calls.empty(); ++i) {
    atendimentos[i] = calls.front(); calls.pop();
    t_atendimentos[i] = 1;
    if (atendimentos[i] < menor) {
      menor = atendimentos[i];
    }
  }

  while(1) {
    menor = 31;

    for (int i = 0; i < n; ++i) {
      if (atendimentos[i] < menor) {
        menor = atendimentos[i];
      }
    }

    for (int i = 0; i < n && !calls.empty(); ++i) {
      int tempo_restante = atendimentos[i] - menor;
      if (tempo_restante == 0) {
        atendimentos[i] = calls.front(); calls.pop();
        t_atendimentos[i]++;
      } else {
        atendimentos[i] = tempo_restante;
      }
    }

    if (calls.empty()) break;
  }

  for (int i = 0; i < n; ++i) {
    printf("%d %d\n", i + 1, t_atendimentos[i]);
  }
}