#include<string>
#define s(v) scanf("%d",&v);
int main(){int t,c,i,j;s(t);while(t--){s(c);int m[c][c];
    for (i=0;i<c;i++)for (j=0;j<=i; j++)s(m[i][j]);
    for (i = c - 2; i >= 0; i--)for (j = 0; j <= i; j++)m[i][j] += std::max(m[i + 1][j + 1], m[i + 1][j]);
    printf("%d\n", m[0][0]);
  }
}