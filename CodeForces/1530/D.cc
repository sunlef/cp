/***

    Filename:   D.cc
    Author:     CleanBlue
    Time:       2021-07-18 14:24:32 utc+8
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

/*---VARIABLE---*/ MAXN(204514) /*---VARIABLE---*/
int n;
int a[SIZE], b[SIZE], c[SIZE];
VI V[SIZE];
int ans[SIZE];
int ans_cnt;

void solve(){
    ans_cnt = 0;
    cin >> n;
    FOR(i,1,n) ans[i] = b[i] = 0, V[i].clear();
    FOR(i,1,n) cin >> a[i];
    FOR(i,1,n) V[a[i]].EB(i);

    int cnt = 0;
    FOR(i,1,n){
        if(V[i].size() == 0)
            continue;
        ++ans_cnt;
        b[i] = V[i][0];
        FOr(j,1,V[i].size()) c[++cnt] = V[i][j];
    }

    FOR(i,1,n)
        if(!b[i])
            b[i] = c[cnt--];
    
    FOR(i,1,n)
        ans[b[i]] = i;

    FOR(i,1,n){
        if(ans[i] == i){
            DIV;
            int u =  b[a[i]];
            cout << "u = b[a[" << i << "]] = " << u << ENDL;
            cout << "ans[u] = " << ans[u] << ENDL;
            cout << "ans[i] = " << ans[i] << ENDL;
            cout << "b[ans[u]] = " << b[ans[u]] << ENDL;
            cout << "b[ans[i]] = " << b[ans[i]] << ENDL;
            b[ans[u]] = i;
            b[ans[i]] = u;
            swap(ans[i], ans[u]);
        }
    }

    cout << ans_cnt << ENDL;
    FOR(i,1,n)
        cout << ans[i] << ' ';
    cout << ENDL;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    unsigned _TvT_ = 1;
    cin >> _TvT_;
    SOLVE_CASE;
    return 0;
}