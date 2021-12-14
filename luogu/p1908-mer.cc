#include <bits/stdc++.h>
using namespace std;

int main() {
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
            b = a;
            
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

            a = b;
        }
    };

    merge(0, n);
    cout << ans << '\n';

    return 0;
}