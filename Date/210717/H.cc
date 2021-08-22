/***

    Filename:   H.cc
    Author:     CleanBlue
    Time:       2021-07-17 16:23:13 utc+8
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
const int    MAXN = 504514;

int n;
int a[SIZE];

bool check(int x){
    unordered_map<int, bool> mp;
    FOR(i,1,n) {
        if(mp[a[i] % x])
            return false;
        mp[a[i] % x] = true;
    }
    return true;
}
bool visted[SIZE];

void solve(){


    bool flag = false;
    int maxx = -INF;
    scanf("%d", &n);
    FOR(i,1,n) { scanf("%d", a+i); maxx = max(maxx, a[i]); if(a[i] == 0) flag = true;}

    if(flag)
        ++maxx;

    DEC(i,maxx,n){
        if(visted[i])
            continue;
        if(check(i))
            continue;
        else{
            for(int j = 1; j*j <= i; ++j){
                if(i%j)
                    continue;
                visted[j] = visted[i/j] = true;
            }
        }
    }

    FOR(i,n,maxx) if(!visted[i]) {cout << i << ENDL; return;}
}

signed main(){
   // ios::sync_with_stdio(0); cin.tie(0);
    solve();

    return 0;
}