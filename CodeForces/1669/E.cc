#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<string> a(n);
    for (auto &i : a) {
        cin >> i;
    }

    sort(a.begin(), a.end());

    int64_t ans = 0;

    int pos = 0;
    for (int i = 0; i < n; i = pos) {
        int p1 = upper_bound(a.begin(), a.end(), a[i]) - a.begin();
        string t = a[i];
        t[1] = 'k';
        int p2 = upper_bound(a.begin(), a.end(), t) - a.begin();

        ans += int64_t(p1 - pos) * int64_t(p2 - p1);
        pos = p1;
    }

    for (auto &i : a) {
        reverse(i.begin(), i.end());
    }

    sort(a.begin(), a.end());

    pos = 0;
    for (int i = 0; i < n; i = pos) {
        int p1 = upper_bound(a.begin(), a.end(), a[i]) - a.begin();
        string t = a[i];
        t[1] = 'k';
        int p2 = upper_bound(a.begin(), a.end(), t) - a.begin();

        ans += int64_t(p1 - pos) * int64_t(p2 - p1);
        pos = p1;
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int QvQ = 1; QvQ <= T; ++QvQ) {
        solve();
    }

    return 0;
}