#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    int64_t ans = 0;

    cin >> n;

    int64_t now = 0;
    vector<tuple<int, int64_t, int64_t>> left, right;

    for (int i = 0; i < n; ++i) {
        int c;
        cin >> c;

        if (i % 2 == 0) {
            left.emplace_back(make_tuple(i, now + 1, now + c));
            now += c;
        } else {
            right.emplace_back(make_tuple(i, now - c + 1, now));
            now -= c;
        }
    }

    for (auto &[a, b, c] : left) {
        cout << b << ' ' << c << '\n';
    }
    cout << "======\n";

    for (auto &[a, b, c] : right) {
        cout << b << ' ' << c << '\n';
    }
    cout << "======\n";


    auto check = [&](int64_t x, int64_t rangl, int64_t rangr, int lidx, int ridx) -> bool {
        auto CUT = x - 1;
        for (auto &[idx, l, r] : right) {
            if (idx < lidx) {
                continue;
            } else if (idx >= ridx) {
                return true;
            }
            cout << "check :" << ' ' << idx << ' ' << l - 1 << ' ' << CUT << '\n';
            if (l - 1 < CUT) {
                return false;
            }
        }
        return true;
    };

    for (auto &[idx, lo, hi] : right) {
        for (int i = 0; i < int(left.size()); ++i) {
            auto ll = get<1>(left[i]), lr = get<2>(left[i]);
            auto lidx = get<0>(left[i]);

            if (lidx > idx) {
                break;
            }

            if (lr < lo || ll > hi) {
                continue;
            }

            int64_t rangl = std::max(ll, lo), rangr = std::min(lr, hi);
            int64_t g = INT64_MAX;
            int64_t l = rangl, r = rangr + 1;
            while (l < r) {
                int64_t mid = (l + r + 1) / 2;
                if (check(mid, rangl, rangr, lidx, idx)) {
                    g = l = mid;
                } else {
                    r = mid - 1;
                }
            }
            if(g == INT64_MAX) {
                continue;   
            }
            if (idx == 5) {
                cout << g << " " << rangl << '\n';
            }
            ans += g - rangl + 1;
            cout << idx << ' ' << lidx << ' ' << i << ' ' << ans << '\n';
        }
    }

    cout << ans << '\n';

    return 0;
}