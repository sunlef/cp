#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;

    int cnt = 0;
    for (int x, i = 0; i < N; ++i) {
        cin >> x;
        if (x < M) {
            ++cnt;
        }
    }

    cout << (N - cnt * 2 > 0 ? N - cnt * 2 : -1) << '\n';
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