#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    auto is_up = [] (char x) {
        return x >= 'A' && x <= 'Z';
    };
    auto is_lo = [] (char x) {
        return x >= 'a' && x <= 'z';
    };

    s = "." + s;
    bool b1 = true, b2 = true;
    for(int i = 1; i < s.size(); ++i) {
        char ch = s[i];
        if(i&1 && is_up(ch)) b1 = false;
        if(!(i&1) && is_lo(ch)) b2 = false;
    }

    if(b1 && b2) cout << "Yes" << '\n';
    else cout << "No" << '\n';

    return 0;
}
