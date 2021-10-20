#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 50;
    cout << T << '\n';
    while(T--) {
        cout << 1 << endl;
        int n = 101;
        cout << n << endl;
        for(int i = 1; i <= n; ++i)
            cout << i << " ";
        cout << endl;
        for(int i = n; i >= 1; --i)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
