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
*Requer: mx (matriz de adjacencia), d(vetor de distancias), v (vertice inicial)
*Efeito(s): minimiza os valores de d
* 
*O(m * log(n))
*/

#define MAX 10
#define INF 0xf3f3f3f3

#include <bits/stdc++.h>
using namespace std;

vector<int> d(MAX, INF); 
vector<vector<pair<int, int>>> mx(MAX); 

void dijkstra(int v)
{
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
