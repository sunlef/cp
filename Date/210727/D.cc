/***

    Filename:   D.cc
    Author:     CleanBlue
    Time:       2021-07-27 12:31:41 utc+8
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

const long double EPS  = 1e-11;
const long double PI   = acos(-1.0);
const int    INF  = 0x3f3f3f3f;
const LL     LINF = 0x3f3f3f3f3f3f3f3fLL;

/*---VARIABLES---*/ MAXN(114514) /*---VARIABLES---*/
bool diff(long double a, long double b){
    if(fabs(a - b) <= EPS) return false;
    return true;
}

struct Node{
    LL xa, ya, xb, yb;
    long double k;
    bool operator < (const Node& B) const {
        return diff(k, B.k) && k < B.k ;
    }
}a[SIZE];

int ans[SIZE];
int cnt[SIZE];
int n;

/*----------- SOLVE CASES -----------*/
void solve(){
    cin >> n;
    FOR(i,1,n) cnt[i] = 0;
    FOR(i,1,n) cin >> a[i].xa >> a[i].ya >> a[i].xb >> a[i].yb;
    FOR(i,1,n){
        if(diff(a[i].xa, a[i].xb))
           a[i].k = 1.0*(a[i].yb - a[i].ya) / (a[i].xb - a[i].xa);
        else a[i].k = INF + 114514;
    } 
    sort(a+1, a+n+1);
    int idx = 0;
    FOR(i,1,n){
        if(i == 1) ++cnt[++idx];
        else{ 
            if(diff(a[i].k, a[i-1].k)) ++cnt[++idx];
            else ++cnt[idx];
        }
    }
    int zushu = 1, len = idx, lst = 0;
    FOR(i,1,n) {
        ans[i] = i - zushu;
        if(i - lst == len){
            lst = i;
            FOR(j,1,idx){
                --cnt[j];
                if(cnt[j] == 0) --len;
            }
            ++zushu;
        }
    }
    FOR(i,1,n) cout << ans[i] << ENDL;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    unsigned _TvT_ = 1;
    cin >> _TvT_;
    SOLVE_CASES;
    return 0;
}