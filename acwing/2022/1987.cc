#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<char, int>> A(N);
    for (auto &[op, len] : A) {
        cin >> len >> op;
    }

    vector<pair<char, int>> vec;
    vec.push_back(A.front());

    for (int i = 1; i < N; ++i) {
        if (A[i].first == A[i - 1].first) {
            vec.back().second += A[i].second;
        } else {
            vec.push_back(A[i]);
        }
    }

    vector<pair<int, int>> RANGES;

    int L = 0, R = 0, now = 0;
    for (int i = 0; i < int(vec.size()); ++i) {
        if (vec[i].first == 'L') {
            int l = max(L, now - vec[i].second);
            int r = now;
            RANGES.push_back({l, r});
            now -= vec[i].second;
        } else {
            int l = now;
            int r = min(R, now + vec[i].second);
            RANGES.push_back({l, r});
            now += vec[i].second;
        }

        L = min(L, now);
        R = max(R, now);
    }

    sort(RANGES.begin(), RANGES.end());
    int64_t ans = 0;
    L = INT_MIN, R = INT_MIN;
    for (auto [l, r] : RANGES) {
        if (l > R) {
            if (l != INT_MIN) {
                ans += R - L;
            }
            L = l, R = r;
        } else {
            R = max(R, r);
        }
    }
    if (L != INT_MIN) {
        ans += R - L;
    }

    cout << ans << '\n';
    return 0;
}