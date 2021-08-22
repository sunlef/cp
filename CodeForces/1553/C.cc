/***

    Filename:   C.cc
    Author:     CleanBlue
    Time:       2021-07-22 23:47:59 utc+8
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
string s;
int calcleft1(int x){
    switch(x){
        case 1: return 4;
        case 2: return 4;
        case 3: return 3;
        case 4: return 3;
        case 5: return 2;
        case 6: return 2;
        case 7: return 1;
        case 8: return 1;
        case 9: return 0;
        case 10: return 0;
    }
    return 0;
}
int calcleft2(int x){
    switch(x){
        case 1: return 5;
        case 2: return 4;
        case 3: return 4;
        case 4: return 3;
        case 5: return 3;
        case 6: return 2;
        case 7: return 2;
        case 8: return 1;
        case 9: return 1;
        case 10: return 0;
    }
    return 0;
}
int calc1(){
    int t1 = 0, t2 = 0;
    FOR(i,1,10){
        if(i&1){
            if(s[i] == '1' || s[i] == '?')
                ++t1;
        }
        else{
            if(s[i] == '1' || s[i] == '?')
                ++t2;
        }
        if(t1 > t2 && calcleft2(i) < t1 - t2) return i;
        if(t2 > t1 && calcleft1(i) < t2 - t1) return i;
    }
    return 10;
} 
int calc2(){
    int t1 = 0, t2 = 0;
    FOR(i,1,10){
        if(i&1){
            if(s[i] == '1' || s[i] == '?')
                ++t1;
        }
        else{
            if(s[i] == '1' )
                ++t2;
        }
        if(t1 > t2 && calcleft2(i) < t1 - t2) return i;
        if(t2 > t1 && calcleft1(i) < t2 - t1) return i;
    }
    return 10;
}
int calc3(){
    int t1 = 0, t2 = 0;
    FOR(i,1,10){
        if(i&1){
            if(s[i] == '1')
                ++t1;
        }
        else{
            if(s[i] == '1' || s[i] == '?')
                ++t2;
        }
        if(t1 > t2 && calcleft2(i) < t1 - t2) return i;
        if(t2 > t1 && calcleft1(i) < t2 - t1) return i;
    }
    return 10;
} 
int calc4(){
    int t1 = 0, t2 = 0;
    FOR(i,1,10){
        if(i&1){
            if(s[i] == '1' )
                ++t1;
        }
        else{
            if(s[i] == '1')
                ++t2;
        }
        if(t1 > t2 && calcleft2(i) < t1 - t2) return i;
        if(t2 > t1 && calcleft1(i) < t2 - t1) return i;
    }
    return 10;
}
/*----------- SOLVE CASES -----------*/
void solve(){
    cin >> s;
    s = " " + s;
    cout << min({calc1(), calc2(), calc3(), calc4()}) << ENDL;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    unsigned _TvT_ = 1;
    cin >> _TvT_;
    SOLVE_CASES;
    return 0;
}