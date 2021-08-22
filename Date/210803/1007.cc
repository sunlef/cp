/***

    Filename:   1007.cc
    Author:     CleanBlue
    Time:       2021-08-03 14:37:06 utc+8
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
//const LL     LINF = 0x3f3f3f3f3f3f3f3fLL;
const int mod = 1000000007;
void ADD(LL& x,LL v){x=(x+v)%mod;if(x<0)x+=mod;}
/*---VARIABLES---*/ MAXN(114514) /*---VARIABLES---*/
LL qpow(LL m, LL k, LL p) {
    LL res = 1 % p, t = m;
    while (k) {
        if (k & 1) res = res * t % p;
        t = t * t % p;
        k >>= 1;
    }
    return res;

}
LL getInv(LL a) {
    return qpow(a, mod - 2, mod);
}
LL calc_maxx(LL x){
    LL res = 1 % mod;
    FOR(i,1,4) res = res * x % mod;
    FOR(i,1,2) res = res * (x+1) % mod;
    res = res * (2*x+1) % mod;
    res = res * getInv(12) % mod;
    return res;
}
LL calc_minn(LL x){
    LL a = -20;
    LL b = x % mod;
    LL c = 9;
    FOR(i,1,2) c = c * x % mod;
    LL d = 4;
    FOR(i,1,3) d = d * x % mod;
    ADD(a,b);
    ADD(a,c);
    ADD(a,d);
    a = a * getInv(12) % mod;
    a = a * x % mod;
    a = a * (x + 1) % mod;
    ADD(a,2);
    return a;
}
/*----------- SOLVE CASES -----------*/
void solve(){
    LL a;
    cin >> a;
    cout << calc_minn(a) << ENDL;
    cout << calc_maxx(a) << ENDL;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    unsigned _TvT_ = 1;
    cin >> _TvT_;
    SOLVE_CASES;
    return 0;
}