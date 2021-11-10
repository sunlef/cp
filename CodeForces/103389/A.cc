#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, X, Y;
    cin >> n >> X >> Y;
    --X, --Y;

    vector<int> k(n);
    for (auto &x : k) {
        cin >> x;
    }

    int m;
    cin >> m;
    vector<int> p(m);
    for (auto &x : p) {
        cin >> x;
    }

    vector<int> a, b;

    if (X < Y) {
        for (int i = X + 1; i <= X + m; ++i) {
            a.push_back(k[i]);
        }
        for (int i = X - 1; i >= max(0, X - m); --i) {
            b.push_back(k[i]);
        }
    } else {
        for (int i = X - 1; i >= X - m; --i) {
            a.push_back(k[i]);
        }
        for (int i = X + 1; i <= min(n - 1, X + m); ++i) {
            b.push_back(k[i]);
        }
    }

    if (a == b) {
        cout << "Unsure\n";
    } else if (p == a) {
        cout << "Right\n";
    } else {
        cout << "Wrong\n";
    }

    return 0;
}