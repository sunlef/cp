#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int cnt = 0;
    map<string, int> mp;

    string s;
    cin.ignore();
    
    while (getline(cin, s)) {
        ++cnt;
        ++mp[s];
    }

    for (auto [s, a] : mp) {
        cout << s << ' ';
        cout << fixed << setprecision(4) << 100 * double(a) / cnt << '\n';
    }

    return 0;
}