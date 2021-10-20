#include <bits/stdc++.h>
using namespace std;

int get_adj(int x, int b) {
    if((x >> b) & 1) return x - (1 << b);
    else return x + (1 << b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> v((1ll << n), -1);
    int cut = ceil(sqrt(1.0*n));

    v[0] = 1;
    for(int i = 0; i < (1ll << n); ++i){
        int cnt = 0;
        int now = v[i];
        for(int j = 0; j < n; ++j){
            int adj = get_adj(i,j);
            if(v[adj] == now) ++cnt;
            else if(v[adj] == -1) {
                if(cnt < cut) {
                    v[adj] = now;
                    ++cnt;
                } else {
                    v[adj] = !now;
                }
            }
        }

        cout << v[i];
    }

    cout << '\n';
    return 0;
}
