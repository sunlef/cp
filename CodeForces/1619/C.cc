#include <bits/stdc++.h>
using namespace std;

void solve() {
    string a, s;
    cin >> a >> s;

    ranges::reverse(a), ranges::reverse(s);

    while (a.size() < s.size()) {
        a.push_back('0');
    }
    string ans;

    int i, j;
    for (i = 0, j = 0; i < int(s.size()) && j < int(a.size()); ++i, ++j) {
        if (s[i] < a[j]) {
            int A = 10 + s[i] - '0';
            int B = a[j] - '0';
            int C = A - B;
            ans.push_back(C + '0');
            i++;
        } else {
            ans.push_back(s[i] - a[j] + '0');
        }
    }

    while (a.size() < ans.size()) {
        a.push_back('0');
    }
    while (ans.size() < a.size()) {
        ans.push_back('0');
    }

    string tmp;
    for (int i = 0; i < int(a.size()); ++i) {
        int A = a[i] + ans[i] - 2 * '0';
        if (A > 9) {
            tmp.push_back(A % 10 + '0');
            tmp.push_back(1 + '0');
        } else {
            tmp.push_back(A + '0');
        }
    }


    while (tmp.size() < s.size()) {
        tmp.push_back('0');
    }
    while (s.size() < tmp.size()) {
        s.push_back('0');
    }

    if (tmp == s) {
        while (ans.size() && ans.back() == '0') {
            ans.pop_back();
        }
        if (!ans.size()) {
            cout << "0\n";
        } else {
            cout << string(ans.rbegin(), ans.rend()) << '\n';
        }
    } else {
        cout << "-1\n";
    }
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