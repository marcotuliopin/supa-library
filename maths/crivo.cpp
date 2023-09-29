/*
*Crivo de Eratostenes
*
*
*Encontra todos os primos em um determinado intervalo.
*
*O(n*log(log(n)) + q)
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> primos(100000);

/*
*1 caso primo, 0 caso contrario
*/
void crivo(vector<int> primos)
{
    fill(primos.begin(), primos.end() - 1, 1);

    for (int i = 2; i < primos.size(); i++)
    {
        if (!primos[i])
            continue;
        for (int j = 2*i; j < primos.size(); j += i)
            primos[j] = 0;
    }
}

/*
*Armazena o maior divisor do numero
*/
void crivo()
{
    for (int i = 2; i < primos.size(); i++)
    {
        if (primos[i] != 1)
            continue;
        for (int j = i; j < primos.size(); j += i)
            primos[j] = i;
    }
}
