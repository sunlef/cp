#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    
    for (auto &x : a) {
        cin >> x;
    }

    for (int i = 0; i < n; ++i) {
        if (count(a.begin(), a.end(), a[i]) >= n / 2) {
            cout << "-1\n";
            return;
        }
    }

    auto check = [&] (int x) -> bool {
        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            for (int j = 0; j < n; ++j) {
                if (abs (a[i] - a[j]) % x == 0) {
                    ++cnt;
                }
            }
            if (cnt >= n / 2) {
                return true;
            }
        }
        return false;
    };

    for (int x = 2000000; x >= 1; --x) {
        if (check(x)) {
            cout << x << '\n';
            return;
        }
    }
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