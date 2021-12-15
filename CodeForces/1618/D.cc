#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;

	vector<int> a(n);
	for (int &ai : a) {
		cin >> ai;
	}

	ranges::sort(a, greater<>());

	int ans = 0;
	for (int i = 0; i < n - 2 * k; ++i) {
		ans += a.back();
		a.pop_back();
	}

	int m = a.size();
	for (int i = 0; i + m / 2 < m; ++i) {
		if (a[i] == a[i + m / 2]) {
			++ans;
		}
	}

	cout << ans << '\n';
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