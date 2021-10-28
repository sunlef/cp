#include <bits/stdc++.h>
using namespace std;

void solve() {
    using i64 = long long;
    i64 a, b;
    cin >> a >> b;
    string B = to_string(b);
    int len = B.size();
    i64 c = 0;
    for (int i = 0; i < len; ++i) {
        if (c * 10 + 9 <= b) {
            c = c * 10 + 9;
        }
    }
    string C = to_string(c);
    len = C.size();
    if (c == 0) {
        len = 0;
    }
    cout << a * len << '\n';
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