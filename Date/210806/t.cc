#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve(unsigned CASE_NUM){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) 
        cin >> a[i];
    
    int sq = sqrt(n);
    struct Node {
        int max, cnt;
        Node(int max = -0x3f3f3f3f, int cnt = 0) : max(max), cnt(cnt) {}
    };
    vector<Node> bl(ceil(1.0*n/sq), Node());
    for(int i = 0; i < n; ++i){
        int blidx = i / sq;
        if(a[i] > bl[blidx].max){
            bl[blidx].max = a[i];
            bl[blidx].cnt = 1;
        }
        else if(a[i] == bl[blidx].max)
            bl[blidx].cnt ++;
    }
    
    auto calc = [&] (int l, int r){
        --l, --r;
        int lbidx = l / sq;
        int rbidx = r / sq;
        int cnt = 0;
        LL maxx = -0x3f3f3f3f;
        if(rbidx - lbidx <= 1){
            for(int i = l; i <= r; ++i){
                if(a[i] > maxx){
                    maxx = a[i];
                    cnt = 1;
                }
                else if(a[i] == maxx)
                    cnt ++;
            }
        }
        else {
            for(int i = l; i < (lbidx + 1) * sq; ++i){
                if(a[i] > maxx){
                    maxx = a[i];
                    cnt = 1;
                }
                else if(a[i] == maxx)
                    cnt ++;
            }
            for(int i = lbidx + 1; i <= rbidx - 1; ++i){
                if(bl[i].max > maxx){
                    maxx = bl[i].max;
                    cnt = bl[i].cnt;
                }
                else if(bl[i].max == maxx)
                    cnt += bl[i].cnt;
            }
            for(int i = rbidx * sq; i <= r; ++i){
                if(a[i] > maxx){
                    maxx = a[i];
                    cnt = 1;
                }
                else if(a[i] == maxx)
                    ++cnt;
            }
        }
        return maxx * cnt;
    };
    
    LL ans = 0;
    while(m--){
        int l, r;
        cin >> l >> r;
        if(l > r)
            swap(l, r);
        ans += calc(l,r);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unsigned _TvT_ = 1;
    //cin >> _TvT_;
    for(unsigned i = 1; i <= _TvT_; ++i)
        solve(i);

    return 0;
}