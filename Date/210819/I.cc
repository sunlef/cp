#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> vote(N + 1, 0);

    for (int i = 1; i <= N; ++i) {
        int x;
        cin >> x;
        if (i == x) {
            vote[i] = -1;
        } else {
            if (vote[x] != -1) {
                vote[x]++;
            }
        }
    }

    int cnt = 0;
    for (int i = 1; i <= N; ++i) {
        if (vote[i] >= K) {
            ++cnt;
        }
    }

    cout << cnt << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unsigned _TvT_;
    cin >> _TvT_;
    for (unsigned i = 1; i <= _TvT_; ++i) {
        solve();
    }

    return 0;
}
