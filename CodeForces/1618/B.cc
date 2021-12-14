#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<string> a(n - 2);
    for (auto &s : a) {
        cin >> s;
    }

    bool flag = true;
    int pos = -1;
    for (int i = 1; i < n - 2; ++i) {
    	if (a[i][0] != a[i - 1][1]) {
    		flag = false;
    		pos = i;
    	}
    }

    if (flag) {
    	cout << 'a';
    	for (int i = 0; i < n - 2; ++i) {
    		cout << a[i][0];
    	}
    	cout << a.back().back() << '\n';
    	
    } else {
    	for (int i = 0; i < n - 2; ++i) {
    		if (i == pos) {
    			if (a[i][0] == 'b') {
    				cout << 'a';
    			} else {
    				cout << 'b';
    			}
    		}
    		cout << a[i][0];
    	}
    	cout << a.back().back() << '\n';
    }
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