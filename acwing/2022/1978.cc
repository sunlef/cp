#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<int, int>> vec(N);
    for (auto &[A, B] : vec) {
        cin >> A >> B;
    }

    sort(vec.begin(), vec.end());

    vector<int> PRE_MAX(N, vec.front().second), SUF_MIN(N, vec.back().second);
    for (int i = 1; i < N; ++i) {
        PRE_MAX[i] = max(PRE_MAX[i - 1], vec[i].second);
    }
    for (int i = N - 2; i >= 0; --i) {
        SUF_MIN[i] = min(SUF_MIN[i + 1], vec[i].second);
    }

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        auto [A, B] = vec[i];
        if (PRE_MAX[i] <= B && SUF_MIN[i] >= B) {
            ++ans;
        }
    }

    cout << ans << '\n';
    return 0;
}