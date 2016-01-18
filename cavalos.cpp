#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <vector>

#define MAXN 1000

using namespace std;

struct Edge {
    int from, to, rev, f, cap;

    Edge(int from, int to, int rev, int f, int cap) :
        from(from), to(to), rev(rev), f(f), cap(cap) { };
};

vector <Edge> g[MAXN];
int nodes;
int src,dest;
int dist[MAXN];
int q[MAXN];
int qt;

void addEdge(int s, int t, int cap) {
  g[s].push_back(Edge(s, t, g[t].size(), 0, cap));
  g[t].push_back(Edge(t, s, g[s].size() - 1, 0, 0));
}

bool bfs() {
  fill(dist, dist + nodes, -1);
  dist[src] = 0;
  int qh = 0, qt = 0;
  int q[MAXN];
  q[qt++] = src;
  for (int qh = 0; qh < qt; qh++) {
    int u = q[qh];
    for (int j = 0; j < g[u].size(); j++) {
      Edge &e = g[u][j];
      int v = e.to;
      if (dist[v] < 0 && e.f < e.cap) {
        dist[v] = dist[u] + 1;
        q[qt++] = v;
      }
    }
  }
  return dist[dest] >= 0;
}

int dfs(int u, int f) {
  if (u == dest) {
    return f;
  }
  for (int i = 0; i < g[u].size(); i++) {
    Edge &e = g[u][i];
    if (e.cap <= e.f) continue;
    int v = e.to;
    if (dist[v] == dist[u] + 1) {
      int df = dfs(v, min(f, e.cap - e.f));
      if (df > 0) {
        e.f += df;
        g[v][e.rev].f -= df;
        return df;
      }
    }
  }
  return 0;
}

int max_flow(int _src, int _dest) {
  src = _src;
  dest = _dest;
  int flow, totflow;

  totflow = 0;
  while (bfs()) {
    while ((flow = dfs(src, INT_MAX))) {
      totflow += flow;
    }
  }
  return totflow;
}

int main() {
  int ik = 0;
  int n, m, k;

  while (scanf("%d %d %d", &n, &m, &k) > 0) {
    int start = 0;
    int end = n + m + 1;

    nodes = end + 1;

    for (int i = 0; i < n; i++) {
      int c;
      scanf("%d ", &c);
      addEdge(start, i + 1, c);
    }

    for (int i = 0; i < k; i++) {
      int h, s;
      scanf("%d %d", &h, &s);
      addEdge(h, n + s, 1);
    }

    for (int i = 0; i < m; i++) {
      addEdge(n + i + 1, end, 1);
    }

    int mf = max_flow(start, end);
    printf("Instancia %d\n%d\n\n", ++ik, mf);
  }

  return 0;
}