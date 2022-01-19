#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;

    while (cin >> N) {
        vector<int64_t> A(N);
        for (int64_t &i : A) {
            cin >> i;
        }

        int64_t ans = -1;
        for (int l = 0; l < N; ++l) {
            for (int r = l; r < N; ++r) {
                int64_t res = 1;
                for (int i = l; i <= r; ++i) {
                    res *= A[i];
                }
                ans = max(ans, res);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}