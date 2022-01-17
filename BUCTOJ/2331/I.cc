#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int A, B, C;

    while (cin >> A >> B >> C) {
        set<string> entry, X_spies;

        for (int i = 0; i < A; ++i) {
            string s;
            cin >> s;
            entry.insert(s);
        }

        vector<string> B_list(B);
        for (string &str : B_list) {
            cin >> str;
        }

        for (int i = 0; i < C; ++i) {
            string s;
            cin >> s;
            X_spies.insert(s);
        }

        bool ok = false;
        for (auto str : B_list) {
            if (entry.count(str) && !X_spies.count(str)) {
                ok = true;
                cout << str << ' ';
            }
        }
        if (!ok) {
            cout << "No enemy spy";
        }
        cout << '\n';
    }

    return 0;
}