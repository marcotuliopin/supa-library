/*
*Sieve of Eratostenes
*
*
*Find all prime numbers in an interval.
*
*O(n*log(log(n)) + q)
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> primos(100000);

/*
*1 if prime, else 0
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
*Stores the largest divider.
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
