/***

    Filename:   C.cc
    Author:     CleanBlue
    Time:       2021-07-25 23:34:26 utc+8
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
#include <unordered_set>
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

/*---VARIABLES---*/ MAXN(250) /*---VARIABLES---*/
int n, k;
bool visted[SIZE];
VPII v;

int calc(int x, int y){
    unordered_set<int> s;
    if(y < x) swap(x,y);
    FOr(i,x+1,y) s.insert(i);
    int res = 0;
    AUTO(i,v){
        if(i.first == x && i.second == y) continue;
        if(s.count(i.first) ^ s.count(i.second)) ++res;
    }
    return res;
}

/*----------- SOLVE CASES -----------*/
void solve(){
    v.clear();
    cin >> n >> k;
    FOR(i,1,2*n) visted[i] = false;
    FOR(i,1,k){
        int a, b;
        cin >> a >> b;
        visted[a] = visted[b] = true;
        if(b < a) swap(a,b);
        v.EB(MP(a,b));        
    }
    int ans = 0;
    AUTO(i,v) ans += calc(i.first, i.second);
    ans /= 2;
    FOR(i,1,2*n){
        if(!visted[i]){
            int maxn = 0, idx, cc = 0;
            bool flag = false;
            FOR(j,1,2*n){
                if(i == j || visted[j])continue;
                int c = calc(i,j);
                if(c > maxn) maxn = cc = c, idx = j, flag = true;
            }
            if(flag){
                visted[i] = visted[idx] = true;
                v.EB(MP(i,idx));
                ans += cc;
            }
            else{
                if(i <= n) v.EB(MP(i,i+n)), visted[i] = visted[i+n] = true;
                else v.EB(MP(i-n,i)), visted[i] = visted[i-n] = true;
            }
        }
    }

    cout << ans << ENDL;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    unsigned _TvT_ = 1;
   // cin >> _TvT_;
    SOLVE_CASES;
    return 0;
}