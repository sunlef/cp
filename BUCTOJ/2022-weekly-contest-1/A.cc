#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    string s;
    cin >> s;
    cout << s.substr(0, 5) << ' ' << s.substr(6, 7) << ' ' << s.substr(14, 5) << '\n';
    
    return 0;
}