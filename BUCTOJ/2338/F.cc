#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string A, B;
    while (cin >> A >> B) {
        cout << ((A.back() - '0') * (B.back() - '0') % 10) << '\n';;
    }

    return 0;
}