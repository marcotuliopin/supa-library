/*
*Knapsack Problem
*
*
*Considere n sacos de pesos {p1, p2, ..., pn} e valores {v1, v2, ..., vn}
*
*Encontra o subconjunto de sacos que maximiza o valor mantendo o peso abaixo 
*de um determinado valor
*
*Requer: n (numero de sacos), p (peso maximo)
*Retorna: valor total do subconjunto otimo
*
*O(n * p)
*/

#include <bits/stdc++.h>
using namespace std;

int knapsack(int n, int p)
{
    vector<pair<int, int>> knapsacks(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> knapsacks[i].second >> knapsacks[i].first; 
    vector<vector<int>> decision_matrix(n + 1, vector<int>(p + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int pi = p; pi >= 0; pi--)
        {
            int choice1 = decision_matrix[i - 1][pi];
            if (knapsacks[i].first > pi)
            {
                decision_matrix[i][pi] = choice1;
                continue;
            }
            int choice2 = knapsacks[i].second + decision_matrix[i - 1][pi - knapsacks[i].first];
            decision_matrix[i][pi] = max(choice1, choice2);
        }
    }
    return decision_matrix[n][p];
}
