#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) {
        cin >> x;
    }
    int now = 1 + (a.front() == 1);
    for (int i = 1; i < n; ++i) {
        if (a[i] == 1) {
            if (a[i - 1] == 1) {
                now += 5;
            } else {
                now += 1;
            }
        } else {
            if (a[i - 1] == 0) {
                cout << "-1\n";
                return;
            }
        }
    }
    cout << now << '\n';
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