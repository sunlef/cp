/***

    Filename:   I.cc
    Author:     CleanBlue
    Time:       2021-07-19 14:15:45 utc+8
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

/*---VARIABLES---*/ MAXN(43) /*---VARIABLES---*/
char m[SIZE][SIZE];
bool check1(int x, int y){
    if(x < 1 || x > 20)
        return false;
    if(y < 1 || y > 20)
        return false;
    if(m[x][y] == '#')
        return false;
    return true;
}
bool check2(int x, int y){
    if(x < 1 || x > 20)
        return false;
    if(y < 21 || y > 40)
        return false;
    if(m[x][y] == '#')
        return false;
    return true;
}
struct Node{
    int step;
    int p1x, p1y, p2x, p2y;
    string ans;
};
bool visted[SIZE][SIZE][SIZE][SIZE];
queue<Node> q;
/*----------- SOLVE CASES -----------*/
void solve(){
    FOR(i,1,20) FOR(j,1,40) cin >> m[i][j];
    Node t = {0,20,20,20,21,""};
    visted[20][20][20][21] = true;
    q.push(t);
    while(q.size()){
        auto u = q.front();
        q.pop();
        
        //cout << u.step << " " << u.p1x << " " << u.p1y << " " << u.p2x << " " << u.p2y << ENDL;
        if((u.p1x == 1 && u.p1y == 20 && u.p2x == 1 && u.p2y == 21) || u.step == 30){
            cout << u.step << ENDL;
            cout << u.ans << ENDL;
            return;
        }
        FOR(i,1,4){
            int n1x,n1y,n2x,n2y;
            string ns;
            if(i == 1){
                n1x = u.p1x;
                n1y = u.p1y - 1;
                n2x = u.p2x;
                n2y = u.p2y + 1;
                bool flag1 = check1(n1x,n1y);
                bool flag2 = check2(n2x,n2y);
                if(!flag1 && !flag2)
                    continue;
                if(!flag1)
                    n1y = u.p1y;
                if(!flag2)
                    n2y = u.p2y;
                if(visted[n1x][n1y][n2x][n2y])
                    continue;
                ns = u.ans + "L";
            }
            else if(i == 2){
                n1x = u.p1x;
                n1y = u.p1y + 1;
                n2x = u.p2x;
                n2y = u.p2y - 1;
                bool flag1 = check1(n1x,n1y);
                bool flag2 = check2(n2x,n2y);
                if(!flag1 && !flag2)
                    continue;
                if(!flag1)
                    n1y = u.p1y;
                if(!flag2)
                    n2y = u.p2y;
                if(visted[n1x][n1y][n2x][n2y])
                    continue;
                ns = u.ans + "R";
            }
            else if(i == 3){
                n1x = u.p1x - 1;
                n1y = u.p1y;
                n2x = u.p2x - 1;
                n2y = u.p2y;
                bool flag1 = check1(n1x,n1y);
                bool flag2 = check2(n2x,n2y);
                if(!flag1 && !flag2)
                    continue;
                if(!flag1)
                    n1x = u.p1x;
                if(!flag2)
                    n2x = u.p2x;
                if(visted[n1x][n1y][n2x][n2y])
                    continue;
                ns = u.ans + "U";
            }
            else{
                n1x = u.p1x + 1;
                n1y = u.p1y;
                n2x = u.p2x + 1;
                n2y = u.p2y;
                bool flag1 = check1(n1x,n1y);
                bool flag2 = check2(n2x,n2y);
                if(!flag1 && !flag2)
                    continue;
                if(!flag1)
                    n1x = u.p1x;
                if(!flag2)
                    n2x = u.p2x;
                if(visted[n1x][n1y][n2x][n2y])
                    continue;
                ns = u.ans + "D";
            }
            visted[u.p1x][u.p1y][u.p2x][u.p2y] = true;
            q.push({u.step + 1, n1x,n1y,n2x,n2y,ns});
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    unsigned _TvT_ = 1;
    //cin >> _TvT_;
    SOLVE_CASES;
    return 0;
}