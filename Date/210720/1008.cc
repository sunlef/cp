/***

    Filename:   1008.cc
    Author:     CleanBlue
    Time:       2021-07-20 13:09:30 utc+8
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

const double EPS  = 1e-6;
const double PI   = acos(-1.0);
const int    INF  = 0x3f3f3f3f;
const LL     LINF = 0x3f3f3f3f3f3f3f3fLL;

/*---VARIABLES---*/ MAXN(2021) /*---VARIABLES---*/
int a[SIZE][SIZE];
int flag[SIZE][SIZE];
int n, m;
int cnt;
vector<pair<int,PII> > v;
/*----------- SOLVE CASES -----------*/
void solve(){
    v.clear();
    scanf("%d%d", &n, &m);
    cnt = 0;
    FOR(i,1,n) FOR(j,1,m) scanf("%d", &a[i][j]);
    int lstx, lsty;
    FOR(j,1,m){
        FOR(i,1,n){
            if(i == 1){
                flag[i][j] = ++cnt;
                lstx = 1, lsty = j;
            }
            else{
                if(a[i][j] >= a[i-1][j])
                    flag[i][j] = flag[i-1][j];
                else{
                    v.EB(MP(j, MP(lstx, i-1)));
                    flag[i][j] = ++cnt;
                    lstx = i, lsty = j;
                }
                if(i == n)
                    v.EB(MP(j, MP(lstx, i)));
            }
        }
    }
    
    if(cnt == n*m || cnt == n*m-1){
        cout << m << ENDL;
        return;
    }

    int ans = -INF;
    AUTO(i,v){
        int el = 0, er = 0;
        int j = i.first;
        int u = i.second.first, d = i.second.second;        
        while(j - el - 1 >= 1 && flag[u][j - el - 1] == flag[d][j - el - 1])
            ++el;
        while(j + er + 1 <= m && flag[u][j + er + 1] == flag[d][j + er + 1])
            ++er;
        ans = max(ans, (d-u+1) * (1 + el + er)) ; 
    }

    cout << ans << ENDL;
}

int main(){
    unsigned _TvT_ = 1;
    scanf("%d", &_TvT_);
    SOLVE_CASES;
    return 0;
}