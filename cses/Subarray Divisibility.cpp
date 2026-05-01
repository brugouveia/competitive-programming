#include <iostream>
#include <map>
using namespace std;

int main()
{
    int n, x;
    long long last = 0, cont = 0;
    cin >> n;

    map<int, long long> qty;
    qty[0] = 1;

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        last = ((x + last) % n + n) % n;

        qty[last]++;
    }

    for (auto [key, val] : qty)
    {
        if (val > 1)
        {
            cont += (val * (val - 1)) / 2;
        }
    }

    cout << cont << endl;
}
