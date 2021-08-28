#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<tuple<int, int, int>> caves(n);
    vector<vector<int>> mosters(n);

    for (int i = 0; i < n; ++i) {
        auto &CAVE = caves[i];
        int k;
        cin >> k;

        int64_t NEED = 0, POWER = 0;
        for (int j = 1; j <= k; ++j) {
            int ARMOR;
            cin >> ARMOR;
            mosters[i].emplace_back(ARMOR);

            if (POWER <= ARMOR) {
                int64_t d = ARMOR + 1 - POWER;
                NEED += d, POWER += d;
            }
            ++POWER;
        }

        get<0>(CAVE) = NEED, get<1>(CAVE) = k, get<2>(CAVE) = i;
    }

    sort(caves.begin(), caves.end(), [](const tuple<int, int, int> &A, const tuple<int, int, int> &B) -> bool const {
        if (get<0>(A) == get<0>(B)) {
            return get<1>(A) > get<1>(B);
        } else {
            return get<0>(A) < get<0>(B);
        }
    });


    auto check = [&](int64_t POWER) -> bool {
        for (int i = 0; i < n; ++i) {
            int idx = get<2>(caves[i]);
            for (auto ARMOR : mosters[idx]) {
                if (POWER <= ARMOR) {
                    return false;
                }
                ++POWER;
            }
        }
        return true;
    };

    int64_t l = 0, r = 100000000000000ll;

    while (l < r) {
        int64_t mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    cout << l << '\n';
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