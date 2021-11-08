#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    struct Node {
        int u, d, l, r;
    };
    string s;
    cin >> s;

    vector<Node> a(s.size() + 1);

    int nowh = 0, noww = 0;
    for (int i = 0; i < s.size(); ++i) {
        auto &now = a[i + 1];
        now = a[i];

        if (s[i] == 'L') {
            --noww;
            now.l = max(now.l, -noww);
        } else if (s[i] == 'R') {
            ++noww;
            now.r = max(now.r, noww);
        } else if (s[i] == 'U') {
            --nowh;
            now.u = max(now.u, -nowh);
        } else {
            ++nowh;
            now.d = max(now.d, nowh);
        }
    }

    int ans = 0;
    for (int i = 0; i < a.size(); ++i) {
        int H = a[i].u + a[i].d;
        int W = a[i].l + a[i].r;
        if (H + 1 > n || W + 1 > m) {
            break;
        }
        ans = i;
    }

    int h = a[ans].u + 1;
    int w = a[ans].l + 1;
    cout << h << ' ' << w << '\n';
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