#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

void solve() {
    i64 N, K;
    cin >> N >> K;

    vector<int> A(N);
    for (int &i : A) {
    	cin >> i;
    }

    ranges::sort(A);

    vector<int64_t> pre(A.begin(), A.end());

    for (int i = 1; i < N; ++i) {
    	pre[i] += pre[i - 1];
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