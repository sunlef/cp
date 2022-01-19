#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;

    while (cin >> N && N) {
        int CUTOFF = 1;
        for (int i = 1; i <= N; ++i) {
            CUTOFF *= i;
        }

        vector<int> A(N);
        iota(A.begin(), A.end(), 1);
        for (int i = 0; i < CUTOFF; ++i) {
            for (int i : A) {
                cout << i << ' ';
            }
            cout << '\n';
            next_permutation(A.begin(), A.end());
        }
    }

    return 0;
}