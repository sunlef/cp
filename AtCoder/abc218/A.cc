#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;
    cout << (s[n - 1] == 'o' ? "Yes" : "No") << '\n';

    return 0;
}