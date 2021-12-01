#include <bits/stdc++.h>
using namespace std;

void solve() {
    int xa, pa, xb, pb;
    cin >> xa >> pa >> xb >> pb;

    string s1 = to_string(xa);
    string s2 = to_string(xb);

    int len1 = s1.size() + pa;
    int len2 = s2.size() + pb;

    while (s1.size() < s2.size()) {
        s1.push_back('0');
    }
    while (s2.size() < s1.size()) {
        s2.push_back('0');
    }

    if (len1 < len2) {
        cout << "<\n";
    } else if (len1 > len2) {
        cout << ">\n";
    } else {
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] < s2[i]) {
                cout << "<\n";
                return;
            } else if (s1[i] > s2[i]) {
                cout << ">\n";
                return;
            }
        }
        cout << "=\n";
    }
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