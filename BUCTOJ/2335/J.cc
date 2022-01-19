#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, T;
    cin >> N >> T;

    vector<pair<int, int>> shifts(N);
    for (auto &[l, r] : shifts) {
        cin >> l >> r;
    }

    sort(shifts.begin(), shifts.end());

    int ans = 0, now = 0;
    for (int i = 0; i < N;) {
        if (now >= T) {
            break;
        }

        int best = 0;
        while (i < N && shifts[i].first <= now + 1) {
            best = max(best, shifts[i].second);
            ++i;
        }

        if (best) {
            ++ans;
            now = best;
        } else {
            break;
        }
    }

    cout << (now >= T ? ans : -1) << '\n';
    return 0;
}