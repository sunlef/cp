#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    set<int> fac;

    int a, b;
    cin >> a >> b;

    for (int i = 1; i <= sqrt(a); ++i) {
        if (a % i == 0) {
            fac.insert(i);
            fac.insert(a / i);
        }
    }

    vector<int> nums;
    for (int i = 1; i <= sqrt(b); ++i) {
        if (b % i == 0) {
            if (fac.count(i)) {
                nums.push_back(i);
            }
            if (fac.count(b / i)) {
                nums.push_back(b / i);
            }
        }
    }

    sort(nums.begin(), nums.end(), greater<int>());

    int q;
    cin >> q;
    while (q--) {
    	int l, r;
    	cin >> l >> r;

    	int num = *lower_bound(nums.begin(), nums.end(), r, greater<int>());
    	if (l <= num && num <= r) {
    		cout << num << '\n';
    	} else {
    		cout << "-1\n";
    	}
    }

    return 0;
}