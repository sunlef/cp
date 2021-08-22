/***

    Filename:   B.cc
    Author:     CleanBlue
    Time:       2021-07-17 22:48:28 utc+8
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
const int    MAXN = 21;

int h, w;
int c1[SIZE][SIZE];
int c2[SIZE][SIZE];

bool check2(int i, int j){
    if(i-1 > 0 && c2[i-1][j] == 1)
        return false;
    if(j-1 > 0 && c2[i][j-1] == 1)
        return false;
    if(i+1 <= h && c2[i+1][j] == 1)
        return false;
    if(j+1 <= w && c2[i][j+1] == 1)
        return false;
    if(i-1 > 0 && j-1 > 0 && c2[i-1][j-1] == 1)
        return false;
    if(i-1 > 0 && j+1 <= w && c2[i-1][j+1] == 1)
        return false;
    if(i+1 <= h && j-1 > 0 && c2[i+1][j-1] == 1)
        return false;
    if(i+1 <= h && j+1 <= w && c2[i+1][j+1] == 1)
        return false;
    return true;
}

bool check1(int i, int j){
    if(i-1 > 0 && c1[i-1][j] == 1)
        return false;
    if(j-1 > 0 && c1[i][j-1] == 1)
        return false;
    if(i+1 <= h && c1[i+1][j] == 1)
        return false;
    if(j+1 <= w && c1[i][j+1] == 1)
        return false;
    if(i-1 > 0 && j-1 > 0 && c1[i-1][j-1] == 1)
        return false;
    if(i-1 > 0 && j+1 <= w && c1[i-1][j+1] == 1)
        return false;
    if(i+1 <= h && j-1 > 0 && c1[i+1][j-1] == 1)
        return false;
    if(i+1 <= h && j+1 <= w && c1[i+1][j+1] == 1)
        return false;
    return true;
}

int calc1(){
    
    int res = 0;
    c1[1][1] = 1;

    FOR(i,2,w)
        if(check1(1,i)){
            ++res;
            c1[1][i] = 1;
        }
    
    FOR(i,2,h)
        if(check1(i,w)){
            ++res;
            c1[i][w] = 1;
        }
    
    DEC(i,w-1,1)
        if(check1(h,i)){
            ++res;
            c1[h][i] = 1;
        }
    
    DEC(i,h-1,1)
        if(check1(i,1)){
            ++res;
            c1[i][1] = 1;
        }
    
    return res;
}

int calc2(){

    int res = 0;
    c2[1][2] = 1;

    FOR(i,2,w)
        if(check2(1,i)){
            ++res;
            c2[1][i] = 1;
        }
    
    FOR(i,2,h)
        if(check2(i,w)){
            ++res;
            c2[i][w] = 1;
        }
    
    DEC(i,w-1,1)
        if(check2(h,i)){
            ++res;
            c2[h][i] = 1;
        }
    
    DEC(i,h-1,2)
        if(check2(i,1)){
            ++res;
            c2[i][1] = 1;
        }
    
    return res;
}


void solve(){
    cin >> h >> w;
    FOR(i,0,20)FOR(j,0,20)c1[i][j] = c2[i][j] = 0;

    if(calc1() > calc2())
        FOR(i,1,h){
            FOR(j,1,w)
                cout << c1[i][j];
            cout << ENDL;
        }
    
    else
        FOR(i,1,h){
            FOR(j,1,w)
                cout << c2[i][j];
            cout << ENDL;
        }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    unsigned _TvT_ = 1;
    cin >> _TvT_;
    SOLVE_CASE;
    return 0;
}