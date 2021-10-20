#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a[22];
    a[0] = 0;
    for(int i = 1; i <= 21; ++i)
        a[i] = 3*a[i-1] + 3;

    int n;
    cin >> n;
    int pos = lower_bound(a+1, a+22, n) - a;

    using LL = long long;

    LL l = a[pos-1], r = a[pos];
    LL num = r - l;
    LL div = num / 3;

    LL p1 = l + div, p2 = l + 2*div;

    while(l < n && l != r ){
        if(n <= p1) cout << 2, r = p1;
        else if(n <= p2) cout << 3, l = p1, r = p2;
        else cout << 6, l = p2;   
        
        num = r - l;
        div = num / 3;
        p1 = l + div, p2 = l + 2*div;
        

        if(div< 1) break;
    }
    cout << endl;

    return 0;
}
