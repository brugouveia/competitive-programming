#include <iostream>
#include <algorithm>
#include <vector>
 
using namespace std;
 
int main()
{
    long long t, otterpower, ff, monsters;
 
    cin >> t;
 
    while (t--)
    {
        vector<long long> mpwr;
        cin >> monsters >> otterpower >> ff;
 
        while (monsters--)
        {
            long long pwr;
            cin >> pwr;
            mpwr.push_back(pwr);
        }
 
        sort(mpwr.begin(), mpwr.end());
 
        for (auto pwr : mpwr)
        {
            long long max = otterpower - pwr;
 
            if (max < 0)
            {
                break;
            }
 
            if (ff < 0)
            {
                ff = 0;
            }
            
            if (ff < max)
            {
                max = ff;
            }
 
            ff -= max;
            otterpower += max + pwr;
        }
        cout << otterpower << endl;
    }
}
