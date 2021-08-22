#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    vector<int> a(n);
    for(auto &x : a) {
        cin >> x;
    }
    sort(a.begin(), a.end());

    return 0;
}