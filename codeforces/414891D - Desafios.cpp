// https://codeforces.com/group/nituVTsHQX/contest/414891/problem/D
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, q, a, b, type;
    cin >> n >> q;

    long long sum = 0;
    vector<int> vec(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a;
        vec[i] = a;
        sum += a;
    }

    int last2 = 0, timeline = 0;
    vector<int> timelines(n + 1, timeline);

    while (q--) {
        cin >> type >> a;

        if (type == 2) {
            last2 = a;
            timeline++;
            sum = 1ll * n * a;
        }
        else {
            cin >> b;

            if (timelines[a] != timeline) {
                timelines[a] = timeline;
                sum += b - last2;
            } else {
                sum += b - vec[a]; 
            }

            vec[a] = b;
        }

        cout << sum << endl;
    }
}
