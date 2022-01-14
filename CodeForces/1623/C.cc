#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;

    vector<int64_t> A(N);
    for (int64_t &i : A) {
        cin >> i;
    }

    int64_t l = 0, r = 1e9;
    while (l < r) {
        int64_t mid = (l + r + 1) / 2;

        auto B = A;
        for (int i = N - 1; i - 2 >= 0; --i) {
            if (B[i] < mid) {
                break;
            }
            int64_t d = min<int64_t>(A[i], (B[i] - mid)) / 3;
            B[i - 2] += 2 * d;
            B[i - 1] += d;
            B[i] -= 3 * d;
        }

        if (*ranges::min_element(B) >= mid) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }

    cout << l << '\n';
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