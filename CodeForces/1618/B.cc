#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<string> vs(n - 2);
    for (auto &str : vs) {
        cin >> str;
    }

    int pos = -1;
    for (int i = 1; i < n - 2; ++i) {
        if (vs[i - 1][1] != vs[i][0]) {
            pos = i;
        }
    }

    if (pos == -1) {
    	for (int i = 0; i < n - 2; ++i) {
    		cout << vs[i][0];
    	}
    	cout << vs.back().back() << 'a' << '\n';
    } else {
    	for (int i = 0 ; i < n - 2; ++i) {
    		if (pos == i) {
    			if (vs[i][0] == 'a') {
    				cout << 'b';
    			}else {
    				cout << 'a';
    			}
    		}
    		cout << vs[i][0];
    	}
    	cout << vs.back().back() << '\n';
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