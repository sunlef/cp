#include <bits/stdc++.h>
using namespace std;

void solve() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (auto &x : a) {
        cin >> x;
    }

    int64_t ans = 0;
    function<void(int, int)> merge = [&](int l, int r) {
        if (r - l == 1) {
            return;
        } else {
            int mid = (l + r) / 2;

            merge(l, mid);
            merge(mid, r);

            int i = l, j = mid;
            int pos = l;

            while (i < mid && j < r) {
                if (a[i] > a[j]) {
                    ans += mid - i;
                    b[pos++] = a[j++];
                } else {
                    b[pos++] = a[i++];
                }
            }

            while (i < mid) {
                b[pos++] = a[i++];
            }
            while (j < r) {
                b[pos++] = a[j++];
            }

            for (int i = l; i < r; ++i) {
                a[i] = b[i];
            }
        }
    };

    merge(0, n);
    if (ans & 1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
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