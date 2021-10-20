/***

    Filename:   1008.cc
    Author:     CleanBlue
    Time:       2021-07-29 15:50:39 utc+8
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
int n, m, k;
LL ans;
VI v[SIZE];
int f[10001][10001];
bool ex(int x, int y){
    cout << "in" << " " << x << " " << y << ENDL;
    if(x == 1 && y == 1) return true;
    int lessblock_pos = lower_bound(v[x].begin(), v[x].end(), y, less<int>()) - v[x].begin();
        cout << "lessblock_pos =" << lessblock_pos << ENDL;
    int lessblock = v[x][lessblock_pos];
        cout << "lessblock = " << lessblock << ENDL;    
    if(lessblock == y) return false;
    int check = lessblock + 1;
    if(x - 1 == 1 && check == 1) return true;
    if(x - 1 >= 1) return ex(x-1, check);
    else return false;
}

/*----------- SOLVE CASES -----------*/
void solve(){
    memset(f,-1,sizeof f);
    cin >> n >> m >> k;
    FOR(i,1,n) v[i].clear();
    FOR(i,1,n){
        int x,y;
        cin >> x >> y;
        v[x].EB(y);
    }
    FOR(i,1,n) { v[i].EB(0), v[i].EB(m+1); sort(v[i].begin(), v[i].end()); }
    DEC(i,n,1){
        DIV;
        FOr(j,0,v[i].size()-1){
            int check = v[i][j] + 1;
            cout << i << " " << check << ENDL;
            if(check == v[i][j+1]) continue;
            if(i == 1 && check == 1){
                ans += v[1][1] - 1;
                break;
            }
            if(i == 1) continue;
            if(i - 1 >= 1 && ex(i-1, check)) {ans += v[i][j+1] - check; cout << "!" << v[i][j+1] - check << ENDL;}
        }
    }
    cout << ans << ENDL;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    unsigned _TvT_ = 1;
    cin >> _TvT_;
    SOLVE_CASES;
    return 0;
}