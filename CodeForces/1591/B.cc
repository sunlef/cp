#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) {
        cin >> x;
    }
    int ans = 0;
    int now = a.back();
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] > now) {
            ++ans;
            now = a[i];
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int TwT = 1; TwT <= T; ++TwT) {
        solve();
    }

    return 0;
}