#include <bits/stdc++.h>
using namespace std;

string ADD(string lhs, string rhs) {
    reverse(lhs.begin(), lhs.end());
    reverse(rhs.begin(), rhs.end());

    while (lhs.size() < rhs.size()) {
        lhs.push_back('0');
    }
    while (rhs.size() < lhs.size()) {
        rhs.push_back('0');
    }

    int carry = 0;
    string res;
    for (int i = 0; i < int(lhs.size()); ++i) {
        int num = carry + lhs[i] + rhs[i] - 2 * '0';
        res.push_back(num % 10 + '0');
        carry = num / 10;
    }

    if (carry) {
        res.push_back(carry + '0');
    }

    reverse(res.begin(), res.end());
    return res;
};

void solve() {
    string a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << ADD(ADD(a, b), ADD(c, d)) << '\n';
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