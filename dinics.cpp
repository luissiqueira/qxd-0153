#include<stdio.h>
#include<limits.h>
#include<vector>

#define MAXN 1000

using namespace std;

struct Edge {
    int to, rev, f, cap;
    Edge(int to, int rev, int f, int cap):
        to(to), rev(rev), f(f), cap(cap) {};
};

vector<Edge> g[MAXN];
vector<int> dist;
int n, src, dest;

void addEdge(int s, int t, int cap) {
  g[s].push_back(Edge(t, g[t].size(), 0, cap));
  g[t].push_back(Edge(s, g[s].size() - 1, 0, 0));
}

bool bfs() {
  fill(dist.begin(), dist.end(), -1);
  dist[src] = 0;
  int qh = 0, qt = 0;
  int q[MAXN];
  q[qt++] = src;

  for (qh = 0; qh < qt; qh++) {
    int u = q[qh];
    for (int j = 0; j < g[u].size(); j++) {
      Edge & e = g[u][j];
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
  if (u == dest) return f;

  for (int i = 0; i < g[u].size(); i++) {
    Edge & e = g[u][i];

    if (e.cap <= e.f) continue;

    int v = e.to;

    if (dist[v] == dist[u] + 1) {
      int df = dfs(v, std::min(f, e.cap - e.f));
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
  int delta;

  int result = 0;

  while(bfs()) {
    while ((delta = dfs(src, INT_MAX))) {
      result += delta;
    }
  }

  return result;
}

int main() {
  return 0;
}