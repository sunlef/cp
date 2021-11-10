#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    double ans = 1;
    ans /= n;
    
    cout << fixed << setprecision(12) << ans << '\n';

    return 0;
}