/***

    Filename:   1008.cc
    Author:     CleanBlue
    Time:       2021-07-22 17:54:05 utc+8
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

/*---VARIABLES---*/ MAXN(114514) /*---VARIABLES---*/
int n, m;
int t, p;
LL DP1[55][505]; //DP1[i][j] 第i门课花费j天最多能得到的分数
LL DP2[55][505][5];  //DP2[i][j][k] 前i门课，花费j天，最多挂k门课最多能得到的分数
string s;
map<string, int> mp;
VPII v[55];
/*----------- SOLVE CASES -----------*/
void solve(){
    cin >> n;
    mp.clear();
    FOR(i,1,n) v[i].clear();
    FOR(i,1,n) {cin >> s; mp[s] = i;}
    cin >> m;
    FOR(i,1,m){
        int x, y;
        cin >> s >> x >> y;
        v[mp[s]].EB(MP(x,y));
    }
    cin >> t >> p;
    memset(DP1,-0x3f,sizeof DP1);
    memset(DP2,-0x3f,sizeof DP2);
    FOR(i,1,n){
        DP1[i][0] = 0;
        AUTO(met,v[i]) //第i门课的材料met
            DEC(j,t,met.second)
                DP1[i][j] = max(DP1[i][j], min(100ll, max(DP1[i][j], DP1[i][j-met.second] + met.first))); 
    }

    DP2[0][0][0] = 0;
    FOR(i,1,n) FOR(j,0,t) FOR(g,0,p) FOR(k,0,j){
        if(DP1[i][k] >= 60) DP2[i][j][g] = max(DP2[i][j][g], DP2[i-1][j-k][g] + DP1[i][k]);
        else if(g) DP2[i][j][g] = max(DP2[i][j][g], DP2[i-1][j-k][g-1] + DP1[i][k]);
    }

    LL ans = -1;
    FOR(i,0,p) ans = max(ans, DP2[n][t][i]);
    cout << ans << ENDL;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    unsigned _TvT_ = 1;
    cin >> _TvT_;
    SOLVE_CASES;
    return 0;
}