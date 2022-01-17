#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string Q[10000];
    Q[0] = "***###.acm.org/";

    int l = 0, r = 0;
    int now = 0;

    while (true) {
        string op;
        cin >> op;

        if (op == "VISIT") {
            string url;
            cin >> url;
            Q[r = ++now] = url;
            cout << url << '\n';
        } else if (op == "BACK") {
            if (now - 1 < l) {
                cout << "Ignored\n";
            } else {
                cout << Q[--now] << '\n';
            }
        } else if (op == "FORWARD") {
            if (now + 1 > r) {
                cout << "Ignored\n";
            } else {
                cout << Q[++now] << '\n';
            }
        } else {
            break;
        }
    }

    return 0;
}