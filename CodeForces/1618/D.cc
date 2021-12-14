#include <bits/stdc++.h>
using namespace std;
template <typename T_vector> void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());
    for (int i = start; i < end; i++) std::cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}
void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int &ai : a) {
        cin >> ai;
    }

    ranges::sort(a);

    int ans = 0;
    vector<int> b;

    for (int i = 0; i < n; ++i) {
        if (i < n - 2 * k) {
            ans += a[i];
        } else {
            b.push_back(a[i]);
        }
    }

    int m = b.size();
    for (int i = 0; i + m / 2 < m; ++i) {
        if (b[i] >= b[i + m / 2]) {
            ++ans;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    std::cin >> T;
    for (int TwT = 1; TwT <= T; ++TwT) {
        solve();
    }

    return 0;
}