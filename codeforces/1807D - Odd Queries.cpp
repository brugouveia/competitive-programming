#include <iostream>

using namespace std;

int main()
{
    int t, n, q;
    cin >> t;

    while (t--)
    {
        cin >> n >> q;

        long long vet[n];
        long long sum[n + 1];

        for (int i = 0; i < n; i++)
        {
            cin >> vet[i];
        }

        sum[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            sum[i] = sum[i - 1] + vet[i - 1];
        }

        while (q--)
        {
            int a, b;
            long long c;
            cin >> a >> b >> c;

            long long diferenca = b - a + 1;
            long long sumDiferenca = diferenca * c - (sum[b] - sum[a - 1]);

            long long res = sum[n] + sumDiferenca;

            if (res % 2 == 1)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }
}
