#include <bits/stdc++.h>
using namespace std;

int64_t dfs(string &s) {
    if (s == "1") {
        return 0;
    } else if (s[0] == '1') {
        string ss(s.size() - 1, '?');
        for (int i = 0; i < ss.size(); ++i) {
            ss[i] = s[i + 1];
        }

        ++ss[0];
        for (int i = 0; i < ss.size(); ++i) {
            if (ss[i] == '2') {
                ss[i] = 0;
                if (i == ss.size() - 1) {
                    ss.push_back('1');
                } else {
                    ++ss[i + 1];
                }
            }
        }
        
        return dfs(ss) + 2;
    } else {
        string ss(s.size() - 1, '?');
        for (int i = 0; i < ss.size(); ++i) {
            ss[i] = s[i + 1];
        }
        return dfs(ss) + 1;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string s;
    cin >> s;

    reverse(s.begin(), s.end());
    cout << dfs(s) << '\n';

    return 0;
}