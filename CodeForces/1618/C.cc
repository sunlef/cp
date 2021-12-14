#include <bits/stdc++.h>
using namespace std;

#define int int64_t
void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int &ai : a) {
        cin >> ai;
    }

    int odd = 0;
    int even = 0;
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            even = std::gcd(even, a[i]);
        } else {
            odd = std::gcd(odd, a[i]);
        }
    }

    auto check1 = [&](int x) -> bool {
    	for (int i = 0; i < n; ++i) {
    		if (i % 2 == 0 && a[i] % x == 0) {
    			return false;
    		} else if (i % 2 == 1 && a[i] % x != 0) {
    			return false;
    		}
    	}
    	return true;
    };

     auto check2 = [&](int x) -> bool {
    	for (int i = 0; i < n; ++i) {
    		if (i % 2 == 0 && a[i] % x != 0) {
    			return false;
    		} else if (i % 2 == 1 && a[i] % x == 0) {
    			return false;
    		}
    	}
    	return true;
    };

    if (check1(odd) || check2(odd)) {
    	cout << odd << '\n';
    } else if (check1(even) || check2(even)) {
    	cout << even << '\n';
    } else {
    	cout << "0\n";
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    std::cin >> T;
    for (int TwT = 1; TwT <= T; ++TwT) {
        solve();
    }

    return 0;
}