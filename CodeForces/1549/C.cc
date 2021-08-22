/***

    Filename:   C.cc
    Author:     CleanBlue
    Time:       2021-08-01 23:47:53 utc+8
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

const double EPS  = 1e-6;
const double PI   = acos(-1.0);
const int    INF  = 0x3f3f3f3f;
const LL     LINF = 0x3f3f3f3f3f3f3f3fLL;

/*---VARIABLES---*/ MAXN(214514) /*---VARIABLES---*/
int n,m;
int dout[SIZE], din[SIZE];
set<PII> s;
void add(int u, int v){
    if(v > u) swap(u, v);
    s.insert(MP(u,v));
}
void wef4tghjio(int u, int v){
    if(v > u) swap(u, v);
    s.erase(MP(u,v));
}
bool died[SIZE];
/*----------- SOLVE CASES -----------*/
void solve(){
    cin >> n >> m;
    FOR(i,1,m){
        int u, v;
        cin >> u >> v;
        add(u,v);
    }
    int q, op;
    cin >> q;
    int ans = n;
    while(q--){
        cin >> op;
        if(op == 1){
            int u, v;
            cin >> u >> v;
            add(u,v);
        }
        else if(op == 2){
            int u, v;
            cin >> u >> v;
            wef4tghjio(u,v);
        }
        else{
            FOR(i,1,n) dout[i] = din[SIZE] = 0;
            AUTO(i,s) dout[i.first] ++ , din[i.second] ++;
            AUTO(i,s){ 
                -- dout[i.first];
            }
            int ans = 0; 
            FOR(i,1,n) if(dout[i] == 0) { ++ ans; }
            cout << ans << ENDL;
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    unsigned _TvT_ = 1;
    //cin >> _TvT_;
    SOLVE_CASES;
    return 0;
}