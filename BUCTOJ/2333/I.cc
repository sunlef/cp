#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int &i : A) {
        cin >> i;
    }

    sort(A.begin(), A.end());

    vector<int> B;
    B.push_back(A.front());

    for (int i = 1; i < N; ++i) {
        if (A[i] != A[i - 1]) {
            B.push_back(A[i]);
        }
    }

    if (B.size() < 2) {
        cout << "NO\n";
    } else {
        cout << B[1] << '\n';
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