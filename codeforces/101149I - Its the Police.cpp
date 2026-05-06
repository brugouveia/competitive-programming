#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    int n, m, a, b, minDegree = 200005, minDegreeNode = 200005;
    cin >> n >> m;

    vector<set<int>> vec(n + 1);

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        vec[a].insert(b);
        vec[b].insert(a);
    }

    for (int i = 1; i <= n; i++) {
        if (vec[i].size() < minDegree) {
            minDegree = vec[i].size();
            minDegreeNode = i;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << !(i == minDegreeNode || vec[minDegreeNode].count(i)) << " \n"[i == n];
    }
}
