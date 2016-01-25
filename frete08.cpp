#include<queue>
#include<stdio.h>

// https://pt.wikipedia.org/wiki/Algoritmo_de_Kruskal
using namespace std;

typedef struct aresta {

    aresta(int p, int q, int u) : p(p), q(q), u(u) { }

    aresta() { }

    int p, q, u;

    bool operator<(const aresta &v) const {
      return u > v.u;
    }

    bool operator>(const aresta &v) const {
      return u < v.u;
    }

    bool operator==(const aresta &v) const {
      return u == v.u;
    }

} Aresta;

int f[1000];
Aresta arestas[10050];

int find_set(int i) {
  return f[i] == i ? i : (f[i] = find_set(f[i]));
}

void union_set(int i, int j) {
  f[find_set(i)] = find_set(j);
}

bool is_same_set(int i, int j) {
  return find_set(i) == find_set(j);
}

void init_arvores(int n) {
  for (int i = 0; i < n; i++) {
    f[i] = i;
  }
}

int kruskal(int n, int m) {
  init_arvores(n);

  priority_queue<Aresta> q;
  for (int i = 0; i < m; ++i) q.push(arestas[i]);

  int cont = 0;
  int sum = 0;

  while (!q.empty()) {
    Aresta a_minima = q.top(); q.pop();

    if (!is_same_set(a_minima.p, a_minima.q)) {
      cont++;
      sum += a_minima.u;
      union_set(a_minima.p, a_minima.q);
    }
  }

  return sum;
}

int main() {
  int n, m, p, q, u;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i) {
    scanf("%d %d %d", &arestas[i].p, &arestas[i].q, &arestas[i].u);
  }
  printf("%d", kruskal(n, m));
}