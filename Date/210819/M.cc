#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto getnum = [] (char x) {
        return x - '0';
    };

    string s;
    cin >> s;
    int a = 0;
    a += getnum(s[0]);
    a += getnum(s[2]) * 2;
    a += getnum(s[3]) * 3;
    a += getnum(s[4]) * 4;

    a += getnum(s[6]) * 5;
    a += getnum(s[7]) * 6;
    a += getnum(s[8]) * 7;
    a += getnum(s[9]) * 8;
    a += getnum(s[10]) * 9;

    char ch = a % 11 < 10 ? (a % 11) + '0' : 'X';

    if(s[12] == ch) {
        cout << "Right" << '\n';
    } else {
        cout << s.substr(0, 12) << ch << '\n';
    }

    return 0;
}
