#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> A(N);
    for (int &i : A) {
        cin >> i;
    }

    sort(A.begin(), A.end());

    auto calc = [&](int X, int Y) -> int {
        int d = A[Y] - A[X];
        return upper_bound(A.begin(), A.end(), A[Y] + 2 * d) - lower_bound(A.begin(), A.end(), A[Y] + d);
    };

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            ans += calc(i, j);
        }
    }

    cout << ans << '\n';
    return 0;
}