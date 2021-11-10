#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }

    int64_t ans = 0;
    for (int i = 1; i < n; ++i) {
        ans += max(a[i], a[i - 1]);
    }

    cout << ans << '\n';
    return 0;
}