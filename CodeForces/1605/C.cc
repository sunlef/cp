#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    auto check = [&](int x) -> bool {
        for (int i = x - 1; i < n; ++i) {
            vector<char> a(x);
            for (int j = 0; j < x; ++j) {
                a[j] = s[i - j];
            }
            int A = ranges::count(a, 'a');
            int B = ranges::count(a, 'b');
            int C = ranges::count(a, 'c');

            if (A > B && A > C) {
                return true;
            }
        }
        return false;
    };

    for (int i = 2; i <= 12; ++i) {
        if (check(i)) {
            cout << i << '\n';
            return;
        }
    }

    cout << "-1\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int TwT = 1; TwT <= T; ++TwT) {
        solve();
    }

    return 0;
}