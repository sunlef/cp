/***

    Filename:   data.cc
    Author:     CleanBlue
    Time:       2021-07-20 14:41:51 utc+8
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
LL randint (LL l,LL r) { 
    LL k = l;
    r ++;
    k += (1.0 * rand() / RAND_MAX) * (r - l);
    return k;
}
/*
//随机整数：randint(l,r) : [l,r]之间的数.
//      //int n = randint(1, 10);
//随机小写字母：(char) randint ('a','z').
//    大写   ：(char) randint ('A','Z').
//PS：main函数中加这句"srand(time(0)// time(0))"
*/
/*----------- SOLVE CASES -----------*/
void solve(){
    int n = randint(1,50), m = randint(1,50);
    set<char> s;
    s.insert('A');
    cout << n << " " << m << ENDL;
    int posai = randint(1,n), posaj = randint(1,m);
    FOR(i,1,n) {
        FOR(j,1,m){
            if(i == posai && j == posaj){
                cout << 'A';
                continue;
            }
            int t = randint(1,1000);
            if(t >= 46 && t <= 89){
                char x = randint(0,25) + 'A';
                if(!s.count(x)) cout << x, s.insert(x);
                else cout << '.';
            }
            else cout << '.';
        }  
        cout << ENDL;
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    srand(time(0) *  time(0));
    unsigned _TvT_ = 1;
    //cin >> _TvT_;
    SOLVE_CASES;
    return 0;
}