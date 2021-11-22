#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    using i64 = int64_t;
    int n, m;
    cin >> n >> m;
    
    vector<int> a(n), b(m);
    for (auto &x : a) {
        cin >> x;
    }
    for (auto &x : b) {
        cin >> x;
    }
    a.push_back(INT_MAX);
    b.push_back(INT_MAX / 2);

    i64 ans = 0;
    for (int i = 0, j = 0, k = 0; i < m; ++i) {
        while (a[j] < b[i]) {
            ++j;
        }
        k = j;
        while (a[k] == b[i]) {
            ++k;
        }
        ans += k - j;
    }

    cout << ans << '\n';
    return 0;
}