/***

    Filename:   AAA.cc
    Author:     CleanBlue
    Time:       2021-08-06 14:14:37 utc+8
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

#define AUTO(A, B)   for (auto A : (B))
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
LL a, b, c;
template <typename T>
struct MathTemplate{
    T power(T a, T k, T p) { //快速米
        T res = 1 % p;
        a = a % p;
        for(; k; k >>= 1, a = a * a % p)
            if(k&1)
                res = res * a % p;
        return res;
    }
    T gcd(T __m, T __n) { //__gcd
        if (__m == 0) return __n; if (__n == 0) return __m;
        while (__n != 0) { T __t = __m % __n; __m = __n; __n = __t; }
        return __m;
    }
    T lcm(T __m, T __n) { //__lcm
      return (__m != 0 && __n != 0) ? (__m / gcd(__m, __n)) * __n : 0;
    }
    T getRevksm(T a, T p) { //欧拉逆天
        return ksm(a, p-2, p); 
    }
    T exgcd(T a, T b, T &x, T &y){
        if(a == 0 && b == 0) return -1;
        if(b == 0) { x = 1; y = 0; return a;}
        T d = exgcd(b, a%b, y, x);
        y -= a/b*x;
        return d;
    }
    T getRevexgcd(T a, T n) { //扩展欧几里得逆天
        T x, y;
        T d = exgcd(a, n, x, y);
        if(d == 1) return (x%n + n ) % n;
        else return -1;
    }
    void add(T &x,T v, T p) {x=(x+v)%p;if(x<0)x+=p;}
};
/*----------- SOLVE CASES -----------*/
void solve(){
    cin >> a >> b >> c;
    MathTemplate<__uint128_t> m;
    __uint128_t A = a, B = b, C = c;
    __uint128_t D = m.power(A,B,C);
    LL d = D;
    cout << d << ENDL;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    unsigned _TvT_ = 1;
    //cin >> _TvT_;
    SOLVE_CASES;
    return 0;
}