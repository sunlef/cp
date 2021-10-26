#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    vector nxt(n + 2, vector<int>(26, n));
    for (int i = n - 2; i >= 0; --i) {
        for (char ch = 'a'; ch <= 'z'; ++ch) {
            nxt[i][ch - 'a'] = nxt[i + 1][ch - 'a'];
        }
        nxt[i][s[i + 1] - 'a'] = i + 1;
    }

    vector dp(q + 1, vector(q + 1, vector<int>(q + 1, n)));
    dp[0][0][0] = 0;
    vector<string> str(3);

    for (int i = 1; i <= q; ++i) {
        char op;
        int r;
        cin >> op >> r;
        --r;
        if (op == '-') {
            str[r].pop_back();
        } else {
            char ch;
            cin >> ch;
            str[r].push_back(ch);
            auto ch0 = *str[0].rbegin(), ch1 = *str[1].rbegin(), ch2 = *str[2].rbegin();
            int pos0 = (r == 0 ? str[0].size() - 1 : 0);
            int pos1 = (r == 1 ? str[1].size() - 1 : 0);
            int pos2 = (r == 2 ? str[2].size() - 1 : 0);

                
        }
    }

    return 0;
}