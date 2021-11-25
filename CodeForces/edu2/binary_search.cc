#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    
    vector<int> a(n);

    for (auto &x : a) {
        cin >> x;
    }
    
    auto check = [&] (int x) -> bool {
        int l = 0, r = n;
        while (l < r) {
            int mid = (l + r) / 2;
            if (a[mid] >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return a[l] == x;
    };

    while (k--) {
        int x;
        cin >> x;
        cout << (check(x) ? "YES\n" : "NO\n");
    }
    
    return 0;
}