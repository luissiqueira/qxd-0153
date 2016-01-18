#include <stdio.h>
#include <limits.h>
#include <vector>

#define MAXN 300
using namespace std;

struct Edge {
    int from, to, rev, f, cap;

    Edge(int from, int to, int rev, int f, int cap) :
        from(from), to(to), rev(rev), f(f), cap(cap) { };
};

vector<Edge> g[MAXN];
int nodes;
int src, dest;
bool vis[MAXN];
int caps[MAXN + 1];

void init_flow() {
  for (int i = 0; i < nodes; i++)
    g[i].clear();
}

void addEdge(int s, int t, int cap) {
  g[s].push_back(Edge(s, t, g[t].size(), 0, cap));
  g[t].push_back(Edge(t, s, g[s].size() - 1, 0, 0));
}

int find_path(int s, int t, int f) {
  int v, df;
  if (s == t) {
    return f;
  }
  vis[s] = true;
  for (int i = 0; i < g[s].size(); i++) {
    Edge &e = g[s][i];
    if (e.cap - e.f <= 0) continue;
    v = e.to;
    if (!vis[v]) {
      df = find_path(v, t, min(f, e.cap - e.f));
      if (df > 0) {
        e.f += df;
        g[v][e.rev].f -= df;
        return df;
      }
    }
  }
  return 0;
}

int ford_fulkerson(int _src, int _dest) {
  int totflow, flow;
  src = _src;
  dest = _dest;
  totflow = 0;
  fill(vis, vis + nodes, false);
  while ((flow = find_path(src, dest, 0x7fffffff))) {
    totflow += flow;
    fill(vis, vis + nodes, false);
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

    init_flow();

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

    int mf = ford_fulkerson(start, end);
    printf("Instancia %d\n%d\n\n", ++ik, mf);
  }

  return 0;
}

