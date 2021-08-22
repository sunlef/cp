#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    if(n <= 125) cout << 4 << endl;
    else if(n <= 211) cout << 6 << endl;
    else cout << 8 << endl;
    return 0;

}
