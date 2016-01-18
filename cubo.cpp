#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<vector>
#include<stack>
#include<set>
#include<queue>
#include<map>

using namespace std;

enum Direcao {
    Direita, Esquerda, Cima, Baixo
};

class Estado {
private:
    int table[3][3];
    int vazio;
public:
    Estado(vector<int> v);

    Estado(Estado *s);

    void show();

    int posicao(int i, int j) const;
};

