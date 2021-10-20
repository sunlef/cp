/***

    Filename:   239.cc
    Author:     CleanBlue
    Time:       2021-07-28 17:03:37 utc+8
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

/*---VARIABLES---*/ MAXN(204514) /*---VARIABLES---*/
int n;
//冰茶几
int fa[SIZE], rk[SIZE];
void init_set(int size) {FOR(i,1,size) fa[i] = i, rk[i] = 1;}

int getfa(int x) {return fa[x] == x ? x : fa[x] = getfa(fa[x]);}

void merge_set(int x, int y) {
   int u = getfa(x), v = getfa(y);
   if(rk[u] > rk[v]) fa[v] = u, rk[u] += rk[v];
   else fa[u] = v, rk[v] += rk[u];
}
unordered_map<int, int> mp;
/*----------- SOLVE CASES -----------*/
void solve(){
    cin >> n;
    mp.clear();
    init_set(2*n);

    int cnt = 0;
    VPII v;
    FOR(i,1,n){
        int x, y, e;
        cin >> x >> y >> e;
        if(mp.find(x) == mp.end()) mp[x] = ++cnt;
        if(mp.find(y) == mp.end()) mp[y] = ++cnt;
        int X = mp[x], Y = mp[y];
        if(e == 1) merge_set(X,Y);
        else v.EB(MP(X,Y));     
    }
    
    AUTO(i,v){
        if(getfa(i.first) == getfa(i.second)) {
            cout << "NO" << ENDL;
            return;
        }
    }
    cout << "YES" << ENDL;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    unsigned _TvT_ = 1;
    cin >> _TvT_;
    SOLVE_CASES;
    return 0;
}