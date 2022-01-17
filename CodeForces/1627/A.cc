#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, M, R, C;
    cin >> N >> M >> R >> C;

    vector<string> grid(N);
    for (string &i : grid) {
        cin >> i;
    }

    if (grid[R - 1][C - 1] == 'B') {
        cout << "0\n";
        return;
    } else {
        int cnt = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                cnt += grid[i][j] == 'B';
            }
        }
        if (cnt == 0) {
            cout << "-1\n";
        } else {
            int cnt1 = 0, cnt2 = 0;
            for (int i = 0; i < N; ++i) {
                cnt1 += grid[i][C - 1] == 'B';
            }
            for (int j = 0; j < M; ++j) {
                cnt2 += grid[R - 1][j] == 'B';
            }
            if (cnt1 == 0 && cnt2 == 0) {
                cout << "2\n";
            } else {
                cout << "1\n";
            }
        }
    }
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