#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    string s;
    int k;
    cin >> s >> k;
    sort(s.begin(), s.end());
    int idx = 1;
    while (idx++ < k) {
        next_permutation(s.begin(), s.end());
    }

    cout << s << '\n';
    
    return 0;
}