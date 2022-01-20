#include <bits/stdc++.h>
using namespace std;

void solve() {
    int M;
    cin >> M;

    vector<int> s = { 100, 50, 20, 10, 5, 2, 1 };
    vector<int> ans(7);

    for (int i = 0; i < 7; ++i) {
        ans[i] = M / s[i];
        M -= ans[i] * s[i];
    }

    for (auto i = ans.rbegin(); i != ans.rend(); ++i) {
        cout << *i << ' ';
    }
    cout << '\n';
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