/*             ⣀⡀                    
          ⢀⣶⣿⣿⣿⣿⣿⣄                  
         ⢀⣿⣿⣿⠿⠟⠛⠻⣿⠆                 
         ⢸⣿⣿⣿⣆⣀⣀ ⣿⠂   never never gonna let you down          
         ⢸⠻⣿⣿⣿⠅⠛⠋⠈     /             
         ⠘⢼⣿⣿⣿⣃⠠                    
           ⣿⣿⣟⡿⠃                    
           ⣛⣛⣫⡄ ⢸⣦⣀                 
     ⢀⣠⣴⣾⡆⠸⣿⣿⣿⡷⠂⠨⣿⣿⣿⣿⣶⣦⣤⣀           
   ⣤⣾⣿⣿⣿⣿⡇⢀⣿⡿⠋⠁⢀⡶⠪⣉⢸⣿⣿⣿⣿⣿⣇          
  ⢀⣿⣿⣿⣿⣿⣿⣿⣿⡏⢸⣿⣷⣿⣿⣷⣦⡙⣿⣿⣿⣿⣿⡏          
  ⠈⣿⣿⣿⣿⣿⣿⣿⣿⣇⢸⣿⣿⣿⣿⣿⣷⣦⣿⣿⣿⣿⣿⡇          
  ⢠⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇          
  ⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣄         
  ⠸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿         
  ⣠⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿         
  ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠃         
  ⢹⣿⣵⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣯⡁ */
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n + 1), b(m + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; ++i) {
        cin >> b[i];
    }

    sort(b.begin() + 1, b.end());

    vector<int> pos(m + 1);
    function<void(int, int, int, int)> solve = [&](int bl, int br, int al, int ar) {
        if (bl > br) {
            return;
        } else {
            int mid = (bl + br) / 2;
            int cnt = 0;
            for (int i = al; i <= ar; ++i) {
                if (a[i] < b[mid]) {
                    ++cnt;
                }
            }
            int mn = INT_MAX, ps;
            for (int i = al; i <= ar; ++i) {
                if (a[i] > b[mid]) {
                    ++cnt;
                } else if (a[i] < b[mid]) {
                    --cnt;
                }
                if (cnt < mn) {
                    mn = cnt;
                    ps = i;
                }
            }
            pos[mid] = ps;
            solve(bl, mid - 1, al, ps);
            solve(mid + 1, br, ps, ar);
        }
    };

    solve(1, m, 0, n);

    vector<int> res;
    int posa = 1, posb = 1;
    while (posa <= n || posb <= m) {
        while (posb <= m && pos[posb] == posa - 1) {
            res.push_back(b[posb++]);
        }
        if (posa <= n) {
            res.push_back(a[posa++]);
        }
    }

    int64_t ans = 0;
    vector<int> B(n + m);
    function<void(int, int)> calc = [&](int l, int r) {
        if (r - l == 1) {
            return;
        } else {
            int mid = (l + r) / 2;
            calc(l, mid);
            calc(mid, r);
            int i = l, j = mid;
            int pos = l;
            while (i < mid && j < r) {
                if (res[i] > res[j]) {
                    ans += mid - i;
                    B[pos++] = res[j++];
                } else {
                    B[pos++] = res[i++];
                }
            }
            while (i < mid) {
                B[pos++] = res[i++];
            }
            while (j < r) {
                B[pos++] = res[j++];
            }
            for (int i = l; i < r; ++i) {
                res[i] = B[i];
            }
        }
    };

    calc(0, n + m);
    cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    for (int TwT = 1; TwT <= T; ++TwT) {
        solve();
    }

    return 0;
}