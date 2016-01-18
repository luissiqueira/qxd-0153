#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <vector>

#define MAXN 100
using namespace std;



typedef struct Edge{
    int from,to, rev, f, cap;
    Edge(int from, int to, int rev, int f, int cap):
        from(from),to(to), rev(rev), f(f), cap(cap) {};
};

vector <Edge> g[MAXN];
int nodes;
int src,dest;
bool vis[MAXN];
int dist[MAXN];
int e[MAXN];
int h[MAXN];
int q[MAXN];
int qt;

void init_flow()
{
  for(int i = 0; i < nodes; i++)
    g[i].clear();
}

void addEdge(int s, int t, int cap)
{
  g[s].push_back( Edge(s,t, g[t].size(), 0, cap)  );
  g[t].push_back( Edge(t,s, g[s].size()-1, 0, 0)  );
}


int find_path(int s, int t, int f)
{
  int v, df;
  if( s == t )
  {
    return f;
  }
  vis[s] = true;
  for(int i = 0; i < g[s].size(); i++)
  {
    Edge & e = g[s][i];
    if( e.cap - e.f <= 0) continue;
    v  = e.to;
    if( !vis[v] )
    {
      df = find_path(v, t, min(f, e.cap-e.f) );
      if( df > 0)
      {
        e.f += df;
        g[v][e.rev].f -= df;
        return df;
      }
    }
  }
  return 0;
}

/*
Algoritmo Ford-Fulkerson
Complexidade O(E*|f|) = O(V^2*|f|)
*/

int ford_fulkerson(int _src, int _dest)
{
  int totflow, flow;
  src = _src;
  dest = _dest;
  totflow = 0;
  fill( vis, vis + nodes, false);
  while( flow = find_path(src, dest, 0x7fffffff) )
  {
    totflow += flow;
    fill( vis, vis + nodes, false);
  }
  printf("fluxo maximo %d\n", totflow);
  return totflow;
}

/*
Algoritmo Edmonds-Karp
Complexidade O(E^2*V) = O(V^4*V) = O(V^5)
*/

int edmonds_karp(int _src, int _dest)
{
  int q[nodes];
  int qt;
  int pred[nodes];
  int edge[nodes];
  int flow, totflow;
  src = _src;
  dest = _dest;
  totflow = 0;
  while(1)
  {
    qt = 0;
    q[qt++] = src;
    fill( pred, pred + nodes, -1);
    for(int qh = 0; qh < qt && pred[dest] == -1; qh++)
    {
      int u = q[qh];
      for(int i = 0; i < (int)g[u].size(); i++)
      {
        Edge & e = g[u][i];
        if( e.cap - e.f <= 0) continue;
        int v  = e.to;
        if( pred[v]== -1)
        {
          pred[v] = u;
          edge[v] = i;
          q[qt++] = v;
        }
      }
    }
    if( pred[dest] == -1) break;

    int flow = 0x7fffffff;

    for(int v = dest; pred[v] >= 0; v = pred[v])
    {
      Edge & e = g[ pred[v] ][ edge[v] ];
      flow = min( flow, e.cap - e.f );
    }


    for(int v = dest; pred[v] >= 0; v = pred[v])
    {
      Edge & e = g[ pred[v] ][ edge[v] ];
      e.f += flow;
      g[v][e.rev].f -= flow;
    }

    totflow += flow;
  }

  printf("fluxo maximo %d\n", totflow);
  return totflow;
}



bool bfs()
{
  fill(dist, dist + nodes, -1);
  dist[src] = 0;
  int qh = 0, qt = 0;
  int q[MAXN];
  q[qt++] = src;
  for(int qh = 0; qh < qt; qh++)
  {
    int u = q[qh];
    for(int j = 0; j < g[u].size(); j++)
    {
      Edge & e = g[u][j];
      int v = e.to;
      if( dist[v] < 0 && e.f < e.cap )
      {
        dist[v] = dist[u] + 1;
        q[qt++] = v;
      }
    }
  }
  return dist[dest] >= 0;
}

int dfs(int u, int f)
{
  if( u == dest )
  {
    return f;
  }
  for(int i = 0; i < g[u].size(); i++)
  {
    Edge & e = g[u][i];
    if( e.cap <= e.f ) continue;
    int v = e.to;
    if( dist[v] == dist[u] + 1)
    {
      int df = dfs(v, min(f, e.cap-e.f) );
      if(df > 0)
      {
        e.f += df;
        g[v][e.rev].f -= df;
        return df;
      }
    }
  }
  return 0;
}

/*
Algoritmo Dinics
Complexidade O(E*V^2) = O(V^4)
*/

int maxFlow(int _src, int _dest)
{
  src = _src;
  dest = _dest;
  int flow, totflow;

  totflow = 0;
  while( bfs() )
  {
    while( flow = dfs(src, INT_MAX) )
    {
      totflow += flow;
    }
  }
  printf("fluxo maximo %d\n", totflow);
  return totflow;
}




int main()
{
  nodes = 3;
  /*
                   3      2
              0 ------1--------2
              |                |
              |_ _ _ _2_ _ _ _ |
  */

  init_flow();
  addEdge(0,1,3);
  addEdge(1,2,2);
  addEdge(0,2,2);
  edmonds_karp(0,2);
  init_flow();
  addEdge(0,1,3);
  addEdge(1,2,2);
  addEdge(0,2,2);
  ford_fulkerson(0,2);
  init_flow();
  addEdge(0,1,3);
  addEdge(1,2,2);
  addEdge(0,2,2);
  maxFlow(0,2);


}

