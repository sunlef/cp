#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    cin >> N;
    int64_t ans = 0;

    using pii = pair<int, int>;
    vector<pii> point(N);

    for (auto &[x, y] : point) {
        cin >> x >> y;
    }

    sort(point.begin(), point.end());

    map<pii, int> mpx, mpy;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            int X1 = point[i].first, Y1 = point[i].second;
            int X2 = point[j].first, Y2 = point[j].second;
            if (X1 == X2) {
                auto &t = mpy[make_pair(Y1, Y2)];
                ans += t;
                ++t;
            } else if (Y1 == Y2) {
                auto &t = mpx[make_pair(X1, X2)];
                ans += t;
                ++t;
            }
        }
    }

    cout << ans / 2 << '\n';

    return 0;
}