#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;

    bool flag = true;
    for (auto &ch : s) {
        if (ch == '0') {
            flag = false;
            break;
        }
    }

    if (flag) {
        cout << '0' << '\n';
        return;
    }

    flag = true;
    for (auto &ch : s) {
        if (ch == '1') {
            flag = false;
            break;
        }
    }

    if (flag) {
        cout << '1' << endl;
        return;
    }

    int cnt0 = 0;
    for (int i = 0; i < int(s.size()); ++i) {
        if (s[i] != '0') {
            continue;
        }
        int pos = i;
        while (pos + 1 < int(s.size()) && s[pos + 1] == '0') {
            ++pos;
        }
        i = pos;
        ++cnt0;
    }

    if(cnt0 == 1) {
        cout << '1' << '\n';
        return;
    } else {
        cout << '2' << '\n';
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