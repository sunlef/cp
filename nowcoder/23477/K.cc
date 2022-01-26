#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    cin >> s;

    vector<int> cnt(10);
    for (char ch : s) {
        int x = ch - '0';
        if (x != 5) {
            ++cnt[x], ++cnt[5];
        }
    }

    for (int i = 1; i <= 9; ++i) {
        cout << cnt[i] << ' ';
    }

    return 0;
}