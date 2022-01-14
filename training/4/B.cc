#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m, t;
    cin >> n >> m >> t;
    vector<pair<int, int>> row(n+1, make_pair(0, 0));
    vector<pair<int, int>> col(m+1, make_pair(0, 0));

    for(int i = 1; i <= t; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        if(x == 1) {
            row[y] = make_pair(z, i);
        } else {
            col[y] = make_pair(z, i);
        }
    }

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            int a = row[i].second, b = col[j].second;
            if(a > b) {
                cout << row[i].first << ' ';
            } else {
                cout << col[j].first << ' ';
            }
        }
        cout << '\n';
    }
    
    return 0;
}