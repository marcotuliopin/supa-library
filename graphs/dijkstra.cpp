/*
 *Dijkstra
 *
 *
 *Encontra a menor distancia de um vertice v a todos os outros
 *Só funciona para pesos positivos
 *
 *Caso a distancia ate um determinado vertice seja INF, ele faz parte de outro
 *componente do grafo
 *
 *O(m * log(n))
 */



#include <bits/stdc++.h>
using namespace std;

vector<int> d(MAX, INF); // distancia dos vertices a v
vector<vector<pair<int, int>>> mx(MAX); // pares armazenam {distancia, indice}

void dijkstra(int v){

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.emplace(0, v); 

    while(!q.empty())
    {
        auto [du, u] = q.top();
        q.pop();

        if (du > d[u])
            continue;

        for (auto [duw, w] : mx[u])
        {
            if (d[w] > d[u] + duw)
            {
                d[w] = d[u] + duw;
                q.emplace(d[w], w);
            }
        }
    }
}
