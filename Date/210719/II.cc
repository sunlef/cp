/***

    Filename:   II.cc
    Author:     CleanBlue
    Time:       2021-07-19 21:35:47 utc+8
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

/*---VRIABLES---*/ MAXN(21) /*---VARIABLES---*/
char m1[SIZE][SIZE], m2[SIZE][SIZE];
bool visted[SIZE][SIZE][SIZE][SIZE];

struct Node{
    int q1x, q1y, q2x, q2y, step;
    string op;
};
queue<Node> q;

bool check1(int x, int y){
    return x > 0 && x < 21 && y > 0 && y < 21 && m1[x][y] != '#';
}
bool check2(int x, int y){
    return x > 0 && x < 21 && y > 0 && y < 21 && m2[x][y] != '#';
}

void draw(string &op){
    int q1x = 20, q1y = 20, q2x = 20, q2y = 1;
    AUTO(i,op){
        m1[q1x][q1y] = 'A';
        m2[q2x][q2y] = 'A';
        if(i == 'L'){
            if(check1(q1x, q1y - 1)) --q1y;
            if(check2(q2x, q2y + 1)) ++q2y;
        }
        else if(i == 'R'){
            if(check1(q1x, q1y + 1)) ++q1y;
            if(check2(q2x, q2y - 1)) --q2y;
        }
        else if(i == 'U'){
            if(check1(q1x - 1, q1y)) --q1x;
            if(check2(q2x - 1, q2y)) --q2x;
        }
        else{
            if(check1(q1x + 1, q1y)) ++q1x;
            if(check2(q2x + 1, q2y)) ++q2x;
        }
    }
    m1[1][20] = m2[1][1] = 'A';
}

/*----------- SOLVE CASES -----------*/
void solve(){
    FOR(i,1,20){
        FOR(j,1,20) cin >> m1[i][j];
        FOR(j,1,20) cin >> m2[i][j];
    }

    Node now, nxt;
    now.q1x = 20, now.q1y = 20;
    now.q2x = 20, now.q2y = 1;
    now.step = 0;

    visted[20][20][20][1] = true;
    q.push(now);

    while(!q.empty()){
        now = q.front();
        q.pop();

        nxt.step = now.step + 1;

        FOR(i,1,4){
            nxt.q1x = now.q1x, nxt.q1y = now.q1y;
            nxt.q2x = now.q2x, nxt.q2y = now.q2y;

            if(i == 1){
                if(check1(nxt.q1x, nxt.q1y - 1)) --nxt.q1y;
                if(check2(nxt.q2x, nxt.q2y + 1)) ++nxt.q2y;
                nxt.op = now.op + "L";
            }
            else if(i == 2){
                if(check1(nxt.q1x, nxt.q1y + 1)) ++nxt.q1y;
                if(check2(nxt.q2x, nxt.q2y - 1)) --nxt.q2y;
                nxt.op = now.op + "R";
            }
            else if(i == 3){
                if(check1(nxt.q1x - 1, nxt.q1y)) --nxt.q1x;
                if(check2(nxt.q2x - 1, nxt.q2y)) --nxt.q2x;
                nxt.op = now.op + "U";
            }
            else{
                if(check1(nxt.q1x + 1, nxt.q1y)) ++nxt.q1x;
                if(check2(nxt.q2x + 1, nxt.q2y)) ++nxt.q2x;
                nxt.op = now.op + "D";
            }

            if(!visted[nxt.q1x][nxt.q1y][nxt.q2x][nxt.q2y]){
                if(nxt.q1x == 1 && nxt.q1y == 20 && nxt.q2x == 1 && nxt.q2y == 1){
                    cout << nxt.step << ENDL;
                    cout << nxt.op << ENDL;
                    draw(nxt.op);
                    FOR(j,1,20){
                        FOR(k,1,20) cout << m1[j][k];
                        cout << " ";
                        FOR(k,1,20) cout << m2[j][k];
                        cout << ENDL;
                    }
                    return;
                }
                visted[nxt.q1x][nxt.q1y][nxt.q2x][nxt.q2y] = true;
                q.push(nxt);
            }
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