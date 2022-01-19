#include <bits/stdc++.h>
using namespace std;

void solve() {
    string S;
    cin >> S;

    stack<char> stk;
    int ans = 0;
    for (auto ch : S) {
        if (ch == '(' || ch == '[') {
            stk.push(ch);
        } else {
            if (ch == ')') {
                if (stk.empty()) {
                    ++ans;
                } else if (stk.top() == '(') {
                    stk.pop();
                } else {
                    ++ans;
                }
            } else {
                if (stk.empty()) {
                    ++ans;
                } else if (stk.top() == '[') {
                    stk.pop();
                } else {
                    ++ans;
                }
            }
        }
    }

    ans += stk.size();
    cout << ans << '\n';
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