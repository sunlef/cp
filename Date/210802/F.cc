/***

    Filename:   F.cc
    Author:     CleanBlue
    Time:       2021-08-02 15:37:32 utc+8
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
#define MP make_pair
#define LB  lower_bound
#define UB  upper_bound
#define EB  emplace_back
#define PQ  priority_queue
#define DIV cout << "=====\n"
#define AUTO(A, B)   for (auto A : B)
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
const LL     LINF = 0x3f3f3f3f3f3f3f3fLL;
/*---VARIABLES---*/ MAXN(114514) /*---VARIABLES---*/
int n, m;
LL tot;
struct Node{
    LL t;
    int idx;
    int cnt;
    int pos1, pos2;
    LL st1, ed1;
    LL st2, ed2;
    bool operator < (const Node &B) const{
        return t  > B.t;
    }
}a[SIZE];
struct Node2{
    int cnt;
    int pos1, pos2;
    LL st1, ed1, st2, ed2;
}ans[SIZE];
LL maxx;
/*----------- SOLVE CASES -----------*/
void solve(){
    cin >> n >> m;
    maxx = -LINF;
    FOR(i,1,n){
        a[i].idx = i;
        cin >> a[i].t;
        a[i].cnt = 0;
        tot += a[i].t;
        maxx = max(maxx, a[i].t);
    }
    sort(a+1, a+n+1);
    tot = ceil(1.0*tot/m);
    tot = max(tot, maxx);
    int nowidx = 1;
    LL nowsum = 0;
    FOR(i,1,n){
        if(nowsum + a[i].t < tot){
            a[i].cnt = 1;
            a[i].pos1 = nowidx;
            a[i].st1 = nowsum;
            a[i].ed1 = nowsum + a[i].t;
            nowsum += a[i].t;
        }
        else if(nowsum + a[i].t == tot){
            a[i].cnt = 1;
            a[i].pos1 = nowidx;
            a[i].st1 = nowsum;
            a[i].ed1 = tot;
            ++nowidx;
            nowsum = 0;
        }
        else{
            a[i].cnt = 2;
            a[i].pos1 = nowidx+1;
            a[i].pos2 = nowidx;
            a[i].st1 = 0;
            a[i].ed1 = a[i].t - (tot - nowsum);
            a[i].st2 = nowsum;
            a[i].ed2 = tot;
            ++nowidx;
            nowsum = a[i].ed1; 
        }
    }
    FOR(i,1,n){
        if(a[i].cnt == 2){
            ans[a[i].idx].cnt = 2;
            ans[a[i].idx].pos1 = a[i].pos1;
            ans[a[i].idx].pos2 = a[i].pos2;
            ans[a[i].idx].st1 = a[i].st1;
            ans[a[i].idx].ed1 = a[i].ed1;
            ans[a[i].idx].st2 = a[i].st2;
            ans[a[i].idx].ed2 = a[i].ed2;            
        }
        else{
            ans[a[i].idx].cnt = 1;
            ans[a[i].idx].pos1 = a[i].pos1;
            ans[a[i].idx].st1 = a[i].st1;
            ans[a[i].idx].ed1 = a[i].ed1;
        }
    }
    FOR(i,1,n){
        cout << ans[i].cnt << " ";
        if(ans[i].cnt == 1) cout << ans[i].pos1 << " " << ans[i].st1 << " " << ans[i].ed1 << ENDL;
        else cout << ans[i].pos1 << " " << ans[i].st1 << " " << ans[i].ed1 << " "
                  << ans[i].pos2 << " " << ans[i].st2 << " " << ans[i].ed2 << ENDL;
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    unsigned _TvT_ = 1;
    //cin >> _TvT_;
    SOLVE_CASES;
    return 0;
}
