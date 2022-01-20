#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;

    while (cin >> s) {
        list<char> l;

        int now = -1;
        auto it = begin(l);

        for (char ch : s) {
            if (ch != '[' && ch != ']') {
                if (now == -1) {
                    l.push_back(ch);
                } else {
                    l.insert(it, ch);
                    advance(it, now);
                }
            } else {
                if (ch == '[') {
                    it = begin(l);
                    now = 0;
                } else {
                    now = -1;
                }
            }
        }
        for (auto ch : l) {
            cout << ch;
        }
        cout << '\n';
    }

    return 0;
}