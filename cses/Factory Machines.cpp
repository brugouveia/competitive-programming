#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long n, t;

long long f(long long time, vector<int> &vec)
{
    long long prods = 0;

    for (int i = 0; i < n && prods <= t; i++)
    {
        prods += time / vec[i];
    }

    return prods;
}

long long binarySearch(vector<int> &vec)
{
    long long l = 0, r = 1e18, ans = 0;

    while (l <= r)
    {
        long long mid = (l + r) / 2;
        long long prods = f(mid, vec);

        if (prods >= t)
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    return ans;
}

int main()
{
    cin >> n >> t;

    vector<int> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }

    cout << binarySearch(vec) << endl;
}
