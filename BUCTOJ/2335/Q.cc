#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, N1, N2;
    while (cin >> N1 >> N2 >> N && !(N == 0 && N1 == 0 && N2 == 0)) {
        vector<int64_t> A(N);
        for (int64_t &i : A) {
            cin >> i;
        }

        sort(A.begin(), A.end(), greater<int64_t>());

        for (int i = 1; i < N; ++i) {
            A[i] += A[i - 1];
        }

        int cnt = N - N1 - N2;
        cout << fixed << setprecision(6) << double(A[N - N2 - 1] - A[N1 - 1]) / cnt << '\n';
    }

    return 0;
}