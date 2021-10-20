/***

    Filename:   C.cc
    Author:     CleanBlue
    Time:       2021-07-17 23:18:19 utc+8
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

#define DIV  cout << "=====\n"
#define EB   emplace_back
#define ENDL '\n'
#define LB   lower_bound
#define MP   make_pair
#define PQ   priority_queue
#define SIZE MAXN
#define UB   upper_bound

#define SOLVE_CASE   FORA(CASE_NUM, 1, _TvT_) solve()
#define AUTO(A, B)   for (auto A : B)
#define DEC(A, B, C) for (auto A = (B); A >= (C); --A)
#define FOR(A, B, C) for (auto A = (B); A <= (C); ++A)
#define FOr(A, B, C) for (auto A = (B); A <  (C); ++A)
#define FORA(A,B, C) for (A = (B); A <= (C); ++A)
#define FOrA(A, B,C) for (A = (B); A <  (C); ++A)
#define DECA(A, B,C) for (A = (B); A >= (C); --A)

typedef long long                LoveLive;
typedef long double              LD;
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
typedef vector<int>              VI;
typedef vector<LoveLive>         VLL;
typedef vector<double>           VD;
typedef vector<string>           VS;

const double PI   = acos(-1.0);
const double EPS  = 1e-7;
const int    INF  = 0x3f3f3f3f;
const int    MAXN = 114514;

int n;
VLL a, b;

void solve(){
    cin >> n;
    a.clear(),b.clear();
    FOR(i,1,n){LL x; cin >> x; a.EB(x);}
    FOR(i,1,n){LL x; cin >> x; b.EB(x);}

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    FOr(i,1,n)a[i] += a[i-1];
    FOr(i,1,n)b[i] += b[i-1];

    int nn = n, k = nn - nn/4;
    int ans = 0;

    while(1){
        LL suma = nn-k-1 >= 0 ? a[nn-1] - a[nn-k-1] : a[nn-1]; 
        LL sumb = nn - k <= n ? (n-k-1 >= 0 ? b[n-1] - b[n-k-1] :  b[n-1] ) : b[k-1];
        if(suma >= sumb)
            break;
        a.EB(a[nn-1] + 100);
        b.EB(b[nn-1]);
        ++nn;
        k = nn - nn/4;
        ++ans;
    }
    cout << ans << ENDL;

}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    unsigned _TvT_ = 1;
    cin >> _TvT_;
    SOLVE_CASE;
    return 0;
}