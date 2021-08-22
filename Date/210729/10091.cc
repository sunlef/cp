/***

    Filename:   10091.cc
    Author:     CleanBlue
    Time:       2021-07-29 14:18:05 utc+8
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

/*---VARIABLES---*/ MAXN(114514) /*---VARIABLES---*/
string s[31];
VI ans2, ans1;
bool isempty(int j){
    FOR(i,1,30) if(s[i][j] != '.') return false;
    return true;
}
/*----------- SOLVE CASES -----------*/
void solve(){
    ans1.clear();ans2.clear();
    cout << "Case #" << CASE_NUM << ":" << ENDL;
    FOR(i,1,30) cin >> s[i];
    FOR(i,1,30) s[i] = "." + s[i];
    int cnt = 0;
    DEC(j,99,1){
        if(cnt >= 7) break;
        if(isempty(j+1) && !isempty(j)) ans2.EB(j), ++ cnt;
    }
    reverse(ans2.begin(), ans2.end());
    FOR(j,2,100){
        if(isempty(j-1) && !isempty(j)){
            ans1.EB(j);
            break;
        }
    }
    cnt = 0;
    FOR(j,ans2[0]+1,100){
        if(cnt >= 6) break;
        if(isempty(j-1) && !isempty(j)) ans1.EB(j);
    }
    FOr(i,0,7) cout << ans1[i] << " " << ans2[i] << ENDL;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    unsigned _TvT_ = 1;
    cin >> _TvT_;
    SOLVE_CASES;
    return 0;
}