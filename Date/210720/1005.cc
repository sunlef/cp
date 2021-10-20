/***

    Filename:   1005.cc
    Author:     CleanBlue
    Time:       2021-07-20 12:32:03 utc+8
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

/*---VARIABLES---*/ MAXN(10000010) /*---VARIABLES---*/
int gcd(LL a, LL b){
    return b == 0 ? a : gcd(b,a%b);
}
int lcm(LL a, int b){
    return a*b / gcd(a,b);
}
vector<pair<LL,PII> > v;
//冰茶几
int fa[SIZE];
int getfa(int x) { return x == fa[x] ? x : fa[x] = getfa(fa[x]); }
void unionfa(int u, int v) { fa[getfa(u)] = getfa(v); }
/*----------- SOLVE CASES -----------*/
void solve(){
    int n;
    cin >> n;
    FOR(i,2,n){
        FOR(j,i+1,n){
            v.EB(MP(lcm(i,j), MP(i,j)));
            v.EB(MP(lcm(i,j), MP(j,i)));
        }
    }
    sort(v.begin(), v.end());
    LL ans = 0;
    int cnt = 0;
    FOR(i,1,n)
        fa[i] = i;
    AUTO(i,v){        
        int u = i.second.first, v = i.second.second;
        LL w = i.first;
       // cout << u << " " << v << " " << w << ENDL;
        if(getfa(u) != getfa(v)){
            ans += w;
            ++cnt;
            unionfa(u,v);
        }
        if(cnt == n - 2)
            break;
    }
    cout << ans << ENDL;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    unsigned _TvT_ = 1;
    //cin >> _TvT_;
    SOLVE_CASES;
    return 0;
}