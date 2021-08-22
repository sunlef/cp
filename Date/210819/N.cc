#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);

    for (auto& x : a) {
        cin >> x;
    }

    int pos = 0;
    int ans = 0;
    while (1) {
        ++ans;
        int sum = 0;
        while (pos < n) {
            if(sum + a[pos] <= m) {
                sum += a[pos];
                ++pos;
            } else {
                break;
            }
        }
        if(pos >= n) {
            break;
        }
    }

    cout << ans << '\n';

    return 0;
}
