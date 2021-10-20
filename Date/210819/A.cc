#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int a;
    cin >> a;
    cout << a + a << '\n';
    vector<int> b(a);
    sort(b.begin(), b.end());
    
    
    return 0;
}