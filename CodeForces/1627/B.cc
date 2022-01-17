#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;

    vector<int> ans(N * M);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            ans[i * M + j] = max(i, N - i - 1) + max(j, M - j - 1);
        }
    }

    ranges::sort(ans);
    for (int i : ans) {
        cout << i << ' ';
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