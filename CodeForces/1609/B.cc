#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    int now = 0;
    for (int i = 2; i < n; ++i) {
        if (s[i] == 'c' && s[i - 1] == 'b' && s[i - 2] == 'a') {
            ++now;
        }
    }

    while (q--) {
        int pos;
        char ch;
        cin >> pos >> ch;
        --pos;

        bool flag = false;
        char tmp = 'z';
        if (s[pos] == 'a' && pos + 2 < n && s[pos + 1] == 'b' && s[pos + 2] == 'c') {
            tmp = 'a';
            flag = true;
        } else if (s[pos] == 'b' && pos - 1 >= 0 && pos + 1 < n && s[pos - 1] == 'a' && s[pos + 1] == 'c') {
            tmp = 'b';
            flag = true;
        } else if (s[pos] == 'c' && pos - 2 >= 0 && s[pos - 1] == 'b' && s[pos - 2] == 'a') {
            tmp = 'c';
            flag = true;
        }

        if (tmp == ch) {
            cout << now << '\n';
        } else {
            if (flag) {
                --now;
            }
            s[pos] = ch;
            if (s[pos] == 'a' && pos + 2 < n && s[pos + 1] == 'b' && s[pos + 2] == 'c') {
                ++now;
            } else if (s[pos] == 'b' && pos - 1 >= 0 && pos + 1 < n && s[pos - 1] == 'a' && s[pos + 1] == 'c') {
                ++now;
            } else if (s[pos] == 'c' && pos - 2 >= 0 && s[pos - 1] == 'b' && s[pos - 2] == 'a') {
                ++now;
            }
            cout << now << '\n';
        }
    }

    return 0;
}