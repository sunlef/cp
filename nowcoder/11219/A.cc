#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;

	n %= 2048;
	if (n >= 1024) {
		n -= 2048;
	}

	cout << n << ' ';
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