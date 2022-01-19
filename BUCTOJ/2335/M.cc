#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64_t N;
    while (cin >> N) {
        vector<int> A(N);
        for (int &i : A) {
            cin >> i;
        }

        sort(A.begin(), A.end());

        auto check = [&](int x) -> bool {
            int64_t cnt = 0;
            for (int i = 0; i < N; ++i) {
                cnt += N - (lower_bound(A.begin(), A.end(), A[i] + x) - A.begin());
            }
            return cnt > N * (N - 1) / 4;
        };

        int l = 0, r = 1e9;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (check(mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }

        cout << l << '\n';
    }

    return 0;
}