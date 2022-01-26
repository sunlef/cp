#include <bits/stdc++.h>
using namespace std;

int grid[110][5];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= 3; ++j) {
            cin >> grid[i][j];
        }
    }

    vector<int> cnt(N + 1);

    auto brace = [&](int u, int v) {
        int res = u - v - 1;
        for (int i = u; i > v; --i) {
            res += cnt[i];
        }
        return res;
    };

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= 3; ++j) {
            if (grid[i][j]) {
                int v = i - j;
                while (brace(i, v) < 3) {
                    ++cnt[i];
                }
            }
        }
    }

    cout << accumulate(cnt.begin(), cnt.end(), 0ll) << '\n';
    return 0;
}