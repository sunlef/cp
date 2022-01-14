#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	for (int i = 2; i <= n - 1; ++i) {
		if (gcd(i, n - i - 1) == 1 && 2 * i != n - 1) {
			cout << i << ' ' << n - i - 1 << ' ' << 1 << '\n';
			return;
		} 
	}
	assert(false);
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