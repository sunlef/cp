#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    sort(s.begin(), s.end());

    if (s[0] == s[1] && s[1] == s[2]) {
        cout << "1\n";
    } else if (s[0] == s[1] || s[1] == s[2]) {
        cout << "3\n";
    } else {
        cout << "6\n";
    }

    return 0;
}