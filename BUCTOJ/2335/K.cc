#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int op;
    map<int, int> mp;

    while (cin >> op && op) {
        if (op == 1) {
            int K, P;
            cin >> K >> P;
            mp[P] = K;
        } else if (op == 2) {
            if (mp.empty()) {
                cout << "0\n";
            } else {
                cout << (*mp.rbegin()).second << '\n';
                mp.erase(--mp.end());
            }
        } else {
            if (mp.empty()) {
                cout << "0\n";
            } else {
                cout << (*mp.begin()).second << '\n';
                mp.erase(mp.begin());
            }
        }
    }

    return 0;
}