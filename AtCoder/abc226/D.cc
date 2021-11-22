#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (auto &[x, y] : a) {
        cin >> x >> y;
    }

    set<pair<int, int>> s;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                continue;
            }
            int X = a[j].first - a[i].first;
            int Y = a[j].second - a[i].second;
            int g = gcd(X, Y);
            X /= g, Y /= g;
            if (!s.count(make_pair(X, Y))) {
                s.insert(make_pair(X, Y));
            }
        }
    }

    cout << s.size() << '\n';

    return 0;
}