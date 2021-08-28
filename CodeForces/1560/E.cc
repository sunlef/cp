#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    vector<int> visted(26, 0);
    vector<int> cnt(26, 0);
    string s2;
    for (int i = s.size() - 1; i >= 0; --i) {
        ++cnt[s[i] - 'a'];
        if (!visted[s[i] - 'a']) {
            visted[s[i] - 'a'] = 1;
            s2.push_back(s[i]);
        }
    }
    reverse(s2.begin(), s2.end());
    int SIZE = 0;
    for (int i = 0; i < (int)s2.size(); ++i) {
        char ch = s2[i];
        int CNT = cnt[ch - 'a'];
        int NEED = CNT / (i + 1);
        SIZE += NEED;
    }
    
    string ans = s.substr(0, SIZE);
    string check;
    fill(visted.begin(), visted.end(), 0);

    for (int i = 0; i < (int)s2.size(); ++i) {
        for (int j = 0; j < (int)ans.size(); ++j) {
            if (!visted[ans[j] - 'a']) {
                check.push_back(ans[j]);
            }
        }
        visted[s2[i] - 'a'] = 1;
    }

    if (check != s) {
        cout << -1 << '\n';
    } else {
        cout << ans << ' ' << s2 << '\n';
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    for (int TwT = 1; TwT <= T; ++TwT) {
        solve();
    }

    return 0;
}