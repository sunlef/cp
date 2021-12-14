#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int &x : a) {
        cin >> x;
    }

    vector<int> A, B;
    for (int &x : a) {
        if (x < 0) {
            A.push_back(-x);
        } else {
            B.push_back(x);
        }
    }

    ranges::sort(A, greater<int>()), ranges::sort(B, greater<int>());
    vector<int64_t> C;

    for (int i = 0; i < int(A.size()); i += k) {
        C.push_back(A[i]);
    }
    for (int i = 0; i < int(B.size()); i += k) {
        C.push_back(B[i]);
    }
    ranges::sort(C);
    
    int64_t ans = 0;
    for (auto &x : C) {
        ans += 2 * x;
    }
    ans -= C.back();
    
    cout << ans << '\n';
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