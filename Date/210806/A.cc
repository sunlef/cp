/***

    Filename:   A.cc
    Author:     CleanBlue
    Time:       2021-08-06 14:41:21 utc+8
    Site:       cleanblue.moe

***/
#include <bits/stdc++.h>
unsigned CASE_NUM;
using namespace std;

#define ENDL '\n'
#define MP  make_pair
#define LB  lower_bound
#define UB  upper_bound
#define EB  emplace_back
#define PQ  priority_queue
#define DIV cout << "=====\n"

#define AUTO(A, B)   for (auto A : (B))
#define MAXN(x)      const int SIZE = (x);
#define FORA(A,B, C) for (A = (B); A <= (C); ++A)
#define FOrA(A, B,C) for (A = (B); A <  (C); ++A)
#define DECA(A, B,C) for (A = (B); A >= (C); --A)
#define SOLVE_CASES  FORA(CASE_NUM, 1, _TvT_) solve()
#define FOR(A, B, C) for (auto A = (B); A <= (C); ++A)
#define FOr(A, B, C) for (auto A = (B); A <  (C); ++A)
#define DEC(A, B, C) for (auto A = (B); A >= (C); --A)

typedef long long                LoveLive;
typedef unsigned long long       ULL;
typedef LoveLive                 LL;
typedef pair<int, int>           PII;
typedef pair<LoveLive, int>      PLI;
typedef pair<LoveLive, LoveLive> PLL;
typedef set<int>                 SI;
typedef set<LoveLive>            SLL;
typedef map<int, int>            MII;
typedef map<LoveLive, int>       MLI;
typedef map<LoveLive, LoveLive>  MLL;
typedef map<char, int>           MCI;
typedef map<string, int>         MSI;
typedef queue<int>               QI;
typedef queue<LoveLive>          QLL;
typedef queue<PII>               QPII;
typedef priority_queue<int>      PQI;
typedef priority_queue<LoveLive> PQLL;
typedef priority_queue<PLI>      PQLI;
typedef vector<int>              VI;
typedef vector<LoveLive>         VLL;
typedef vector<double>           VD;
typedef vector<string>           VS;
typedef vector<PII>              VPII;

//const double EPS  = 1e-6;
//const double PI   = acos(-1.0);
//const int    INF  = 0x3f3f3f3f;
//const LL     LINF = 0x3f3f3f3f3f3f3f3fLL;
/*---VARIABLES---*/ MAXN(514514) /*---VARIABLES---*/
struct Node{
    int max, cnt;
    Node(int max = -0x3f3f3f3f, int cnt = 0) : max(max), cnt(cnt) {}
};
/*----------- SOLVE CASES -----------*/
void solve(){
    int n, m;
    cin >> n >> m;
    int sq = sqrt(n);
    VI a(n);
    vector<Node> bl(ceil(1.0*n/sq), Node());

    FOr(i,0,n) cin >> a[i];
    FOr(i,0,n){
        int idx = i / sq;
        if(a[i] > bl[idx].max){
            bl[idx].max = a[i];
            bl[idx].cnt = 1;
        } 
        else if(a[i] == bl[idx].max) bl[idx].cnt ++;
    }

    function<LL(int, int)> calc = [&] (int l, int r){
        --l, --r;
        int lbidx = l / sq, rbidx = r / sq;
        LL maxx = -0x3f3f3f3f;
        int cnt = 0;
        if(lbidx == rbidx || lbidx + 1 == rbidx){
            FOR(i,l,r){
                if(a[i] > maxx) {
                    maxx = a[i];
                    cnt = 1;
                }
                else if(a[i] == maxx) ++ cnt;
            }
        }
        else{
            FOr(idx, lbidx+1, rbidx){
                if(bl[idx].max > maxx){
                    maxx = bl[idx].max;
                    cnt = bl[idx].cnt;
                }
                else if(bl[idx].max == maxx) cnt += bl[idx].cnt;
            }
            FOR(idx, l, (lbidx + 1) * sq){
                if(bl[idx].max > maxx){
                    maxx = bl[idx].max;
                    cnt = bl[idx].cnt;
                }
                else if(bl[idx].max == maxx) cnt += bl[idx].cnt;
            }
            FOR(idx,rbidx*sq, r){
                if(bl[idx].max > maxx){
                    maxx = bl[idx].max;
                    cnt = bl[idx].cnt;
                }
                else if(bl[idx].max == maxx) cnt += bl[idx].cnt;
            }
        }
        return maxx * cnt;
    };

    LL ans = 0;
    while(m--){
        int l, r;
        cin >> l >> r;
        cout << calc(l,r) << ENDL;
        ans += calc(l, r);
    }
    cout << ans << ENDL;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    unsigned _TvT_ = 1;
    //cin >> _TvT_;
    SOLVE_CASES;
    return 0;
}