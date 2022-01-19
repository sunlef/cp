#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;

    while (cin >> s) {
        cout << ([&](const string &S) -> bool {
            int now = 0;
            for (auto ch : S) {
                if (ch == '(') {
                    ++now;
                } else {
                    --now;
                }
                if (now < 0) {
                    return false;
                }
            }
            return now == 0;
        }(s)
                                             ? "YES\n"
                                             : "NO\n");
    }

    return 0;
}