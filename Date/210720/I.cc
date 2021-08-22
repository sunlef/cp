/***

    Filename:   I.cc
    Author:     CleanBlue
    Time:       2021-07-20 20:34:15 utc+8
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

/*---VARIABLES---*/ MAXN(114514) /*---VARIABLES---*/
int n, m, k;
vector<pair<int, PII> > vt;
//冰茶几
int fa[SIZE];
int getfa(int x) { return x == fa[x] ? x : fa[x] = getfa(fa[x]); }
void unionfa(int u, int v) { fa[getfa(u)] = getfa(v); }
/*----------- SOLVE CASES -----------*/
void solve(){
    cin >> n >> m >> k;
    while(m--){
        int u, v, c;
        cin >> u >> v >> c;
        vt.EB(MP(c,MP(u,v)));
    }
    sort(vt.begin(), vt.end() );

    FOR(i,1,n) fa[i] = i;
    int cnt = 0, lst = 0;
    AUTO(i,vt){
        if(i.first != lst){
            if(cnt == n - k){
                cout << lst << ENDL;
                return;
            }
            lst = i.first;
        }

        int u = i.second.first, v = i.second.second;
        if(getfa(u) != getfa(v)){
            ++cnt;
            unionfa(u,v);
        }
    }
    if(cnt == n-k){
        cout << lst << ENDL;
        return;
    }
    cout << -1 << ENDL;

}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    unsigned _TvT_ = 1;
    cin >> _TvT_;
    SOLVE_CASES;
    return 0;
}