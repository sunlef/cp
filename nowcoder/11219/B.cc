#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

vector<i64> vec(1, 1);

void solve() {
    i64 x, y;
    cin >> x >> y;
    i64 ans = *lower_bound(vec.begin(), vec.end(), x);
    if (ans <= y) {
        cout << ans << '\n';
    } else {
        cout << "-1\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (vec.back() < 1e9) {
        vec.push_back(vec.back() * 2);
    }

    int T;
    std::cin >> T;
    for (int TwT = 1; TwT <= T; ++TwT) {
        solve();
    }


    return 0;
}