#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	int rb, cb, rd, cd;
	cin >> rb >> cb >> rd >> cd;
	int dr = 1, dc = 1;

	int ans = 0;
	while (rb != rd && cb != cd) {
		++ans;
		rb += dr;
		cb += dc;
		if (rb == 0 || rb == n + 1) {
			dr = -dr;
			rb += 2 * dr;
		}
		if (cb == 0 || cb == m + 1) {
			dc = -dc;
			cb += 2 * dc;
		}
	}

	cout << ans << '\n';
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