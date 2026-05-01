#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n, m, type, l, r;
    cin >> n;

    vector<long long> vet(n), vetU(n), sum(n + 1), sumU(n + 1);

    sum[0] = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> vet[i];
        vetU[i] = vet[i];
        sum[i + 1] = sum[i] + vet[i];
    }

    sort(vetU.begin(), vetU.end());

    sumU[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        sumU[i] = sumU[i - 1] + vetU[i - 1];
    }

    cin >> m;

    while (m--)
    {
        cin >> type >> l >> r;

        if (type == 1)
        {
            cout << sum[r] - sum[l - 1] << endl;
        }
        else
        {
            cout << sumU[r] - sumU[l - 1] << endl;
        }
    }
}
