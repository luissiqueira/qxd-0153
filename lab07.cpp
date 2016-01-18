#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <map>
#define MAX_SIZE 50

using namespace std;

typedef pair<int, int> ii;

int l, c;

int min_turns = -1;

int chart[MAX_SIZE][MAX_SIZE];
int min_turn[MAX_SIZE][MAX_SIZE];

int x[] = {0, 0,  0, 1, -1};
int y[] = {0, 1, -1, 0,  0};

class Estado {
public:
    int x;
    int y;
    int t;

    Estado() {
      x = 0;
      y = 0;
      t = 0;
    }

    Estado(int x, int y, int t) {
      this->x = x;
      this->y = y;
      this->t = t;
    }

    bool operator<(const Estado &e) const {
      if (this->x < e.x) return true;
      if (this->x > e.x) return false;
      if (this->y < e.y) return true;
      if (this->y > e.y) return false;
      if (this->t < e.t) return true;
      return false;
    }
};

void show(Estado e) {
  for (int i = 0; i < l; i++) {
    for (int j = 0; j < c; j++) {
      int v = (chart[l][c] + e.t) % 10;
      printf("%d ", v);
    }
    printf("\n");
  }

  printf("x, y (%d, %d)\n", e.x, e.y);
  printf("turns %d\n", e.t);
  printf("min_turns %d\n", min_turns);
}

int main() {

  while (scanf("%d %d", &l, &c) != EOF) {
    for (int i = 0; i < l; i++) {
      for (int j = 0; j < c; j++) {
        scanf("%d", &chart[i][j]);
      }
    }

    min_turns = -1;

    Estado start;

    queue<Estado> fila;

    for (int i = 1; i <= l; i++)
      for (int j = 1; j <= c; j++)
            min_turn[i][j] = -1;

    fila.push(start);

    while (!fila.empty()) {
      Estado u = fila.front(); fila.pop();

      if (u.x == c && u.y == l) {
        if (min_turns == -1 || u.t < min_turns) {
          min_turns = u.t;
        }
      }

      if (min_turns != -1 && u.t > min_turns) {
        continue;
      }

      int ax, ay;
      ax = u.x;
      ay = u.y;

      int rt = min_turn[ay][ax];

      if (rt == -1 || u.t < rt) {
        min_turn[ay][ax] = u.t;
      }

      for (int k = 0; k < 5; k++) {
        int nx = ax + x[k];
        int ny = ay + y[k];
        int nt = u.t + 1;

        if (nx < 0 || ny < 0) continue;
        if (nx > c || ny > l) continue;

        int h = (chart[ay][ax] + u.t) % 10;
        int nh = (chart[ny][nx] + nt) % 10;

        if (nh > h + 1) continue;

        Estado filho;
        filho.x = nx;
        filho.y = ny;
        filho.t = nt;
        fila.push(filho);
      }
    }

    printf("%d\n", min_turns);
  }

  return 0;
}