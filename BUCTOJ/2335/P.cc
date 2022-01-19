#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;

    int CUFFOFF = 1;
    for (int i = 1; i <= int(s.size()); ++i) {
        CUFFOFF *= i;
    }

    vector<string> a;
    for (int i = 0; i < CUFFOFF; ++i) {
        a.push_back(s);
        next_permutation(s.begin(), s.end());
    }

    sort(a.begin(), a.end(), [](const string &lhs, const string &rhs) {
        vector<int> a(lhs.size()), b(rhs.size());
        for (int i = 0; i < int(lhs.size()); ++i) {
            if (lhs[i] >= 'a' && lhs[i] <= 'z') {
                a[i] = 2 * (lhs[i] - 'a' + 1);
            } else {
                a[i] = 2 * (lhs[i] - 'A' + 1) - 1;
            }
        }
        for (int i = 0; i < int(rhs.size()); ++i) {
            if (rhs[i] >= 'a' && rhs[i] <= 'z') {
                b[i] = 2 * (rhs[i] - 'a' + 1);
            } else {
                b[i] = 2 * (rhs[i] - 'A' + 1) - 1;
            }
        }
        return a < b;
    });
    a.erase(unique(a.begin(), a.end()), a.end());

    for (string i : a) {
        cout << i << '\n';
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