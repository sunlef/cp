/***

    Filename:   DD.cc
    Author:     CleanBlue
    Time:       2021-07-18 15:07:46 utc+8
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
#define MP   make_pair
#define LB   lower_bound
#define UB   upper_bound
#define EB   emplace_back
#define PQ   priority_queue
#define DIV  cout << "=====\n"

#define AUTO(A, B)   for (auto A : B)
#define MAXN(x) const int SIZE = (x);
#define FORA(A,B, C) for (A = (B); A <= (C); ++A)
#define FOrA(A, B,C) for (A = (B); A <  (C); ++A)
#define DECA(A, B,C) for (A = (B); A >= (C); --A)
#define SOLVE_CASE   FORA(CASE_NUM, 1, _TvT_) solve()
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

const double EPS  = 1e-9;
const double PI   = acos(-1.0);
const int    INF  = 0x3f3f3f3f;
const LL     LINF = 0x3f3f3f3f3f3f3f3fLL;

/*---VARIABLE---*/ MAXN(200514) /*---VARIABLE---*/
int n;
int a[SIZE];
int r[SIZE];
int ans[SIZE];
VI v[SIZE];

/**pvp**//*----- SOLVE CASES -----*//**qvq**/
void solve(){
    cin >> n;
    FOR(i,1,n) r[i] = 0, v[i].clear();
    FOR(i,1,n) cin >> a[i];
    FOR(i,1,n) v[a[i]].EB(i);

    VI e;
    int ans_cnt = 0;
    FOR(i,1,n){
        if(v[i].size() == 0) continue;
        ++ans_cnt;
        r[i] = v[i][0];
        FOr(j,1,v[i].size()) e.EB(v[i][j]);
    }

    int cnt = e.size() - 1;
    FOR(i,1,n) if(!r[i]) 
        r[i] = e[cnt--];
    
    FOR(i,1,n) ans[r[i]] = i;

    FOR(i,1,n) if(ans[i] == i){
        int u = r[a[i]];
        r[ans[u]] = i;
        r[ans[i]] = u;
        swap(ans[i], ans[u]);
    }

    cout << ans_cnt << ENDL;
    FOR(i,1,n) cout << ans[i] << " \n"[i == n];
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    unsigned _TvT_ = 1;
    cin >> _TvT_;
    SOLVE_CASE;
    return 0;
}