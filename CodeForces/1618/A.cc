#include <bits/stdc++.h>
using namespace std;

void solve() {
	vector<int> a(7);
	for (int &ai : a) {
		cin >> ai;
	}

	auto b = a;

	auto get = [&] () -> vector<int> {
		vector<int> res;
		res.push_back(b[0]);
		res.push_back(b[1]);
		res.push_back(b[2]);
		res.push_back(b[0] + b[1]);
		res.push_back(b[0] + b[2]);
		res.push_back(b[1] + b[2]);
		res.push_back(b[0] + b[1] + b[2]);
		sort(res.begin(), res.end());
		return res;
	};
	while (get() != a) {
		ranges::next_permutation(b);
	}
	cout << b[0] << ' ' << b[1] << ' ' << b[2] << '\n';
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