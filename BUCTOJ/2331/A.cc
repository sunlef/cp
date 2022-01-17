#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string x;
    while (cin >> x) {
        int64_t A = 0, B = 0;
        reverse(x.begin(), x.end());
        int64_t base = 1;
        for_each(x.begin(), x.end(), [&](char ch) {
            A += base * (ch - '0');
            B += (ch - '0') * (ch - '0') * (ch - '0') * (ch - '0') * (ch - '0') * (ch - '0') * (ch - '0');
            base *= 10;
        });
        cout << (A == B ? "Y\n" : "N\n");
    }

    return 0;
}