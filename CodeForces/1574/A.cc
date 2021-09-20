#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int cnt = 0;
        for (int j = 1; j <= i; ++j) {
            cout << '(';
        }
        for (int j = 1; j <= i; ++j) {
            cout << ')';
        }
        cnt += i;
        cnt = n - cnt;
        for (int j = 1; j <= cnt; ++j) {
            cout << "()";
        }
        cout << endl;
    }
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