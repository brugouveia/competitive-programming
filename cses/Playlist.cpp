#include <iostream>
#include <set>
#include <queue>
using namespace std;

int main()
{
    int n, longest = 0;
    long long x;
    cin >> n;

    set<long long> vis;
    queue<long long> window;

    while (n--)
    {
        cin >> x;

        if (vis.count(x))
        {
            while (window.size() && window.front() != x)
            {
                vis.erase(window.front());
                window.pop();
            }
            if (window.size())
            {
                window.pop();
            }
        }

        vis.insert(x);
        window.push(x);

        if (window.size() > longest)
        {
            longest = window.size();
        }
    }
    cout << longest << endl;
}
