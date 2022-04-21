#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int &i : a) {
        cin >> i;
    }

    int pos = 30;
    while (k) {
        if (pos < 0) {
            break;
        }

        int cnt = n;
        for (int i = 0; i < n; ++i) {
            if ((a[i] >> pos) & 1) {
                --cnt;
            }
        }

        if (k >= cnt) {
            for (int i = 0; i < n; ++i) {
                if (!((a[i] >> pos) & 1)) {
                    a[i] |= (1 << pos);
                    --k;
                }
            }
        }

        --pos;
    }

    for (int i = 1; i < n; ++i) {
        a[0] &= a[i];
    }

    cout << a[0] << '\n';
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