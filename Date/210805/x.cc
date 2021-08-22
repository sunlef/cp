/***

    Filename:   x.cc
    Author:     CleanBlue
    Time:       2021-08-05 23:58:07 utc+8
    Site:       cleanblue.moe

***/
#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <unordered_map>
unsigned CASE_NUM;
using namespace std;

#define ENDL '\n'
#define MP  make_pair
#define LB  lower_bound
#define UB  upper_bound
#define EB  emplace_back
#define PQ  priority_queue
#define DIV cout << "=====\n"

#define AUTO(A, B)   for (auto A : (B)
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
/*---VARIABLES---*/ MAXN(114514) /*---VARIABLES---*/

template<class Dat, class Merge = std::plus<Dat> >
struct SegmentTree{
    const int n;
    const Merge merge;
    vector<Dat> dat;
    SegmentTree(int n) : n(n), merge(Merge()), dat(4 << __lg(n)) {}
    int __lg(int __n) {
        int __k;
        for (__k = 0; __n != 0; __n >>= 1) ++__k;
        return __k - 1;
    }
    SegmentTree(vector<Dat> init) : SegmentTree(init.size()){
        function<void(int, int, int)> build = [&](int p, int l, int r) {
            if(r - l == 1) { dat[p] = init[l]; return; }
            build(p<<1, l, (l+r)>>1);
            build((p<<1)+1, (l+r)>>1, r);
        };
    }
    void modify(int p, int l, int r, int x, const Dat &v) {
        if(r - l == 1) { dat[p] = v; return; }
        int mid = (l+r) >> 1;
        if(x < mid) modify(p<<1, l, mid, x, v);
        else modify((p<<1)+1, mid, r, x, v);
        dat[p] = merge(dat[p<<1], dat[(p<<1)+1]);
    }
    void modify(int p, const Dat &v) { modify(1,0,n,p,v); }
    void modify(int l, int r, const Dat &v) { modify(1,0,n,)}
    Dat query(int p, int l, int r, int x, int y) {
        if(l >= y || r <= x) { return Dat(); }
        if(l >= x && r <= y) { return dat[p]; }
        return merge(query(p<<1, l, (l+r)>>1, x, y), query((p<<1)+1, (l+r)>>1, r, x, y));
    }
    Dat query(int l, int r) { return query(1,0,n,l,r); }
}; 
/*----------- SOLVE CASES -----------*/
void solve(){
    int n, m;
    cin >> n >> m;
    VI a(n);
    FOr(i,0,n) cin >> a[i];
    SegmentTree<int> seg(a);
    FOR(i,1,m){
        int op;
        cin >> op;
        if(op == 1) {
            int x, y, k;
            seg.modify()
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    unsigned _TvT_ = 1;
    //cin >> _TvT_;
    SOLVE_CASES;
    return 0;
}
