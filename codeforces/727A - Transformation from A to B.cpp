#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    vector<int> path;

    while (b > a)
    {
        path.push_back(b);

        if (b % 2 == 0)
        {
            b /= 2;
        }
        else if (b % 10 == 1)
        {
            b /= 10;
        }
        else
        {
            break;
        }
    }

    if (b != a)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
        cout << path.size() + 1 << endl;
        cout << a;
        for (int i = path.size() - 1; i >= 0; i--)
            cout << ' ' << path[i];
        cout << endl;
    }
}
