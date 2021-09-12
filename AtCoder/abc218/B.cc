#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    for (int i = 0; i < 26; ++i) {
        int x;
        cin >> x;
        cout << char(x + 'a' - 1);
    }
    cout << '\n';
    
    return 0;
}