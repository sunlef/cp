/***

    Filename:   Untitled-1
    Author:     CleanBlue
    Time:       2021-07-17 16:09:17 utc+8
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

int n;
int a[SIZE];

bool check(int x){
    unordered_map<int, bool> mp;
    FOR(i,1,n){
        if(mp[a[i] % x])
            return false;
        mp[a[i] % x] = true;
    }
    return true;
}

void solve(){
    cin >> n;
    FOR(i,1,n) {cin >> a[i];}
    FOR(i,1,INF) if(check(i)){cout << i << ENDL; return;}
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    unsigned int _TvT_ = 1;
    //cin >> _TvT_;
    FOR(CASE_NUM, 1, _TvT_)
        solve();
    return 0;
}