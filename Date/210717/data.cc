/***

    Filename:   data.cc
    Author:     CleanBlue
    Time:       2021-07-17 16:12:18 utc+8
    Site:       cleanblue.moe

***/
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

#define DIV  cout << "=====\n"
#define EB   emplace_back
#define ENDL '\n'
#define LB   lower_bound
#define MP   make_pair
#define PQ   priority_queue
#define SIZE MAXN
#define UB   upper_bound

#define AUTO(A, B)   for (auto A : B)
#define DEC(A, B, C) for (int A = (B); A >= (C); --A)
#define FOR(A, B, C) for (int A = (B); A <= (C); ++A)
#define FOr(A, B, C) for (int A = (B); A < (C); ++A)

using namespace std;
typedef long long LoveLive;
typedef long double LD;
typedef unsigned long long ULL;
typedef LoveLive LL;
typedef pair<int, int> PII;
typedef pair<LoveLive, int> PLI;
typedef pair<LoveLive, LoveLive> PLL;
typedef map<int, int> MII;
typedef map<LL, int> MLI;
typedef map<LL, LL> MLL;
typedef map<char, int> MCI;
typedef vector<int> VI;
typedef vector<LoveLive> VLL;
typedef vector<double> VD;
typedef vector<string> VS;

unsigned     int    CASE_NUM;
const double PI   = acos(-1.0);
const double EPS  = 1e-6;
const int    INF  = 0x3f3f3f3f;
const int    MAXN = 114514;

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
bool visted[100000];
void solve(){
    int n = randint(30000, 50000);
    cout << n << ENDL;
    for(int i = 1; i <= n; ++i){
        int m = randint(1, 50000);
        while(visted[m])
            m = randint(1, 50000);
        cout << m << " ";
        visted[m] = true;
    }
    cout << ENDL;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

     srand( (unsigned int) time( NULL ));
    unsigned int _TvT_ = 1;
    //cin >> _TvT_;
    FOR(CASE_NUM, 1, _TvT_)
        solve();

    return 0;
}