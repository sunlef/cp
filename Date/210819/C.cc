#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    while(cin >> a >> b){
        if(a == 0 && b == 0)
            break;
        cout << a + b << '\n';
    }
    return 0;
}
