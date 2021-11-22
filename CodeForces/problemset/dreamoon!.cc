#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }

    sort(a.begin(), a.end());

    int l = 1, r = 2e9;
    while (l < r) {
        int mid = (l + r) / 2;
        int cnt = 0;
        function<void(int, int)> dfs = [&](int pos, int sum) {
            if (cnt >= k || pos == n) {
                return;
            }
            if (sum + a[pos] <= mid) {
                ++cnt;
                dfs(pos + 1, sum + a[pos]);
                dfs(pos + 1, sum);
            }
        };
        dfs(0, 0);
        if (cnt >= k) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    cout << l << '\n';
    return 0;
}