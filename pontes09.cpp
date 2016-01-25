#include <stdio.h>
#include <queue>
#include <string.h>

int g[1100][10200];
int d[1100];
int adj[1100][1100];
int dist[1001];

using namespace std;
typedef struct vt {
    vt(int ID, int D) : id(ID), d(D) { }

    int id, d;

    bool operator<(const vt &v) const {
      return d < v.d;
    }

    bool operator==(const vt &v) const {
      return d == v.d;
    }

    bool operator>(const vt &v) const {
      return d > v.d;
    }
} vertex;

int dijkstra(int n) {
  priority_queue<vertex> q;
  for (int i = 1; i < n + 2; ++i) {
    dist[i] = ~(1 << 31);
  }
  dist[0] = 0;
  q.push(vertex(0, 0));
  while (!q.empty()) {
    vertex s = q.top();
    q.pop();
    for (int i = 0; i < d[s.id]; ++i) {
      int v = adj[s.id][i];
      if (dist[s.id] + g[s.id][v] < dist[v]) {
        dist[v] = dist[s.id] + g[s.id][v];
        q.push(vertex(v, dist[v]));
      }
    }
  }
  return dist[n + 1];
}

int main() {
  int n, m, s, t, b;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n + 2; ++i) {
    for (int j = 0; j < n + 2; ++j) {
      g[i][j] = -1;
    }
  }
  memset(d, 0, sizeof(d));

  for (int k = 0; k < m; ++k) {
    scanf("%d %d %d", &s, &t, &b);
    g[s][t] = b;
    g[t][s] = b;
    adj[t][d[t]++] = s;
    adj[s][d[s]++] = t;
  }
  printf("%d", dijkstra(n));
}