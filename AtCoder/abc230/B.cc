#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    string T = "oxx";
    while (T.size() < 233) {
        T = T + T;
    }
    for (int i = 0; i <= 10; ++i) {
        if (T.substr(i, s.size()) == s) {
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";

    return 0;
}