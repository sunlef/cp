#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

void solve() {
	int n, Fx, X0;
	cin >> n >> Fx >> X0;

	i64 tsum = Fx * n;
	cout << ((n + 1) * X0 + tsum) / (n + 1) << '\n';
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