/***

    Filename:   D.cc
    Author:     CleanBlue
    Time:       2021-07-17 12:08:03 utc+8
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
const int    MAXN = 2001;

int n, m;
string s[SIZE];
string ss;

void solve(){

    cin >> n >> m;
    FOR(i,1,n){
        cin >> s[i];
        s[i] = s[i] + ' ';
    }

    cin >> ss;
    
    VI v;
    FOR(i,1,n){
        int last = -1;
        FOR(j,0,n){
            if(s[i][j] == '0')
                continue;
            else{
                int len = j - last - 1;
                if(len >= m)
                    v.EB(len);
                last = j;
            }
        }
    }

    LL ans = 0;
    AUTO(i,v)
        ans += i - m + 1;
    
    cout << ans << ENDL;

}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    unsigned int _TvT_ = 1;
    //cin >> _TvT_;
    FOR(CASE_NUM, 1, _TvT_)
        solve();

    return 0;
}