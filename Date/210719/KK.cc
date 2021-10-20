/***

    Filename:   KK.cc
    Author:     CleanBlue
    Time:       2021-07-19 23:45:24 utc+8
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

const double EPS  = 1e-9;
const double PI   = acos(-1.0);
const int    INF  = 0x3f3f3f3f;
const LL     LINF = 0x3f3f3f3f3f3f3f3fLL;

/*---VARIABLES---*/ MAXN(1000011) /*---VARIABLES---*/
int n, k;
int b[SIZE], a[SIZE], s[SIZE], top;
/*----------- SOLVE CASES -----------*/
void solve(){
    cin >> n >> k;
    FOR(i,1,k){
        int p, x;
        cin >> p >> x;
        if(x > p){
            cout << -1 << ENDL;
            return;
        }
        b[p] = x;
    }

    FOR(i,1,n) if(!b[i]) b[i] = b[i-1] + 1;

    int now = 0;
    DEC(i,n,1){
        if(top < b[i])
            FOR(j,top+1, b[i]) s[++top] = ++now;
        a[i] = s[top--];
    }

    FOR(i,1,n) cout << a[i] << " \n"[i == n];
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    unsigned _TvT_ = 1;
    //cin >> _TvT_;
    SOLVE_CASES;
    return 0;
}