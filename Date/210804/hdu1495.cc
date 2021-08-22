/***

    Filename:   hdu1495.cc
    Author:     CleanBlue
    Time:       2021-08-04 13:45:36 utc+8
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
/*---VARIABLES---*/ MAXN(114) /*---VARIABLES---*/
int S, A, B;
struct Node{
    int s, a, b;
    int step;
};
queue<Node> q;
bool visted[SIZE][SIZE][SIZE];
/*----------- SOLVE CASES -----------*/
void solve(){
    memset(visted, 0, sizeof visted);
    while(q.size()) q.pop();
    q.push((Node){S,0,0,0});
    visted[S][0][0] = true;
    while(q.size()){
        Node u = q.front();
        q.pop();   
        int t = min(A - u.a, u.s);
        if(!visted[u.s-t][u.a+t][u.b]) { 
            if((u.s - t == u.a + t && u.s-t)|| (u.s - t == u.b && u.b) || (u.a+t == u.b && u.b)){
                cout << u.step + 1 << ENDL;
                DIV;
                return;
            }
            visted[u.s-t][u.a+t][u.b] = true; 
            q.push((Node){u.s-t, u.a+t, u.b, u.step + 1});
        }
        t = min(B - u.b, u.s);
        if(!visted[u.s - t][u.a][u.b + t]){
            if((u.s -t == u.a && u.a )|| (u.s-t == u.b+t && u.b+t) || (u.a == u.b+t && u.a)){
                cout << u.step + 1 << ENDL;
                DIV;
                return;
            }
            visted[u.s-t][u.a][u.b+t] = true;
            q.push((Node){u.s-t, u.a, u.b+t, u.step + 1});
        }
        t = min(S - u.s, u.a);
        if(!visted[u.s+t][u.a-t][u.b]){
            cout << t << ENDL;
            cout << u.s+t << " " << u.a-t << " " << u.b << ENDL;
            if((u.s+t == u.a-t && u.s+t) || (u.s+t == u.b && u.b) || (u.a - t == u.b && u.b)){
                cout << u.step + 1 << ENDL;
                DIV;
                return;
            }
            visted[u.s+t][u.a-t][u.b] = true;
            q.push((Node){u.s+t, u.a-t, u.b, u.step+ 1});
        }
        t = min(B - u.b, u.a);
        if(!visted[u.s][u.a-t][u.b+t]){
            if((u.s && u.s == u.a-t) || (u.s && u.s == u.b+t) || (u.a-t == u.b+t && u.b+t)){
                cout << t << ENDL;
                cout << u.s << " " << u.a << " " << u.b << ENDL;
                cout << u.step+1 << ENDL;
                DIV;
                return;
            }
            visted[u.s][u.a-t][u.b+t] = true;
            q.push((Node){u.s, u.a-t, u.b+t, u.step + 1});
        }
        t = min(S - u.s, u.b);
        if(!visted[u.s+t][u.a][u.b-t]){
            if(( u.a && u.s+t == u.a) || (u.s+t && u.s+t == u.b-t )|| (u.a && u.a == u.b-t)){
                cout << u.step+1 << ENDL;
                return;
            }
            visted[u.s+t][u.a][u.b-t] = true;
            q.push((Node){u.s+t, u.a, u.b-t, u.step + 1});
        }
        t = min(A - u.a, u.b);
        if(!visted[u.s][u.a+t][u.b-t]){
            if((u.s && u.s == u.a+t )|| (u.s && u.s == u.b-t )|| (u.a + t && u.a + t == u.b -t) ){
                cout << u.step + 1 << ENDL;
                return;
            }
            visted[u.s][u.a + t][u.b -  t] = true;
            q.push((Node){u.s,u.a+t,u.b-t,u.step+1});
        }
    }
    cout << -1 << ENDL;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    while(cin >> S >> A >> B && !(S == 0 && B == 0 && A == 0))
        solve();
    return 0;
}