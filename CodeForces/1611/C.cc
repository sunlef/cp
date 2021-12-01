#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }

    if (a.front() != n && a.back() != n) {
        cout << "-1\n";
    } else {
        int l = 0, r = n - 1;
        if (a.front() == n) {
            ++l;
        } else {
            --r;
        }
        vector<int> ansl, ansr;
        ansr.push_back(n);
        int cnt = 1;
        while (cnt < n) {
            if (a[l] > a[r]) {
                ansl.push_back(a[l++]);
            } else {
                ansr.push_back(a[r--]);
            }
            ++cnt;
        }
        for (auto i = ansl.rbegin(); i != ansl.rend(); ++i) {
            cout << *i << ' ';
        }
        for (auto &x : ansr) {
            cout << x << ' ';
        }
        cout << '\n';
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