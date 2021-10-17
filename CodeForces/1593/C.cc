#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(k);
    for (auto &x : a) {
        cin >> x;
    }

    sort(a.rbegin(), a.rend());

    int pos = 0, ans = 0;
    for (auto &x : a) {
        if (x <= pos) {
            break;
        } else {
            pos += n - x;
            ++ans;
        }
    }

    cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    for (int TwT = 1; TwT <= T; ++TwT) {
        solve();
    }

    return 0;
}