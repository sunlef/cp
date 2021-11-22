#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<int> ans;

    int i = 0, j = n - 1;
    while (i < j) {
        while (i < j && s[i] != '1') {
            ++i;
        }
        if (i >= j) {
            break;
        }
        while (i < j && s[j] != '0') {
            --j;
        }
        if (i >= j) {
            break;
        }
        ans.push_back(i);
        ans.push_back(j);
        ++i, --j;
    }

    if (ans.size() == 0) {
        cout << "0\n";
    } else {
        ranges::sort(ans);
        cout << "1\n";
        cout << ans.size() << ' ';
        for (auto &x : ans) {
            cout << x + 1 << ' ';
        }
        cout << '\n';
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