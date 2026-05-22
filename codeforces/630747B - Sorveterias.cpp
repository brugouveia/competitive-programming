#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int n, s;

bool can(vector<int>& vec, int num) {
    int last = vec[0], cont = 1;

    for (int i = 1; i < n; i++) {
        if (vec[i] - last >= num) {
            cont++;
            last = vec[i];
        }
    }

    return cont >= s;
}

int binSearch(vector<int>& vec) {
    int l = 1, r = vec[n - 1] - vec[0], ans = 0;

    while (r >= l) {
        long long mid = (r + l) / 2;
        bool bigger = can(vec, mid);

        if (bigger) {
            ans = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }

    return ans;
}

int main() {
    cin >> n >> s;

    vector<int> vec(n);

    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    cout << binSearch(vec) << endl;
}
