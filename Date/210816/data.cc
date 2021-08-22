#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 1000000;
    cout << n << endl;
    for(int i = 1; i <= n; ++i)
        cout << "(";
    for(int i = 1; i <= n; ++i)
        cout << ")";
    cout << endl;
    for(int i = 1; i <= n; ++i)
        cout << i << " ";
    cout << endl;    

    return 0;
}
