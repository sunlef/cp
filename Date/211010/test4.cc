#include <bits/stdc++.h>
using namespace std;

int cnt = 0;
int n;
string S, s;
void dfs(int step, int pos, string str) {
    if (step == 8) {
        if (str == S) {
            ++cnt;
        }
        return;
    }
    if (pos + 1 <= n) {
        dfs(step + 1, pos + 1, str + s[pos + 1]);
        dfs(step, pos + 1, str);
    }
}

void solve() {
    cin >> s;
    S = "nunhehheh";
    n = s.size();
    s = "?" + s;
    dfs(0, 0, "");
    cout << cnt << endl;
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