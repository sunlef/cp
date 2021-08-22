/***

    Filename:   10091.cc
    Author:     CleanBlue
    Time:       2021-08-03 16:27:21 utc+8
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
/*---VARIABLES---*/ MAXN(1014514) /*---VARIABLES---*/
int a[SIZE];
int n;
LL ans;
int cnt[SIZE<<1], pos[SIZE], num[SIZE];
void work(int l, int r){
    if(l==r) { ++ ans; return;}
    int mid = l+r >> 1;
    work(l,mid); work(mid+1, r);
    DEC(i,mid,l){
        if(++cnt[a[i]] > (mid-i+1) / 2 && !pos[a[i]])
            num[pos[a[i]] = ++num[0]] = a[i]; 
    }
    FOR(i,mid+1,r){
        if(++cnt[a[i]] > (i-mid)/2 && !pos[a[i]])
            num[pos[a[i]] = ++ num[0]] = a[i];
    }
    FOR(i,l,r) pos[a[i]] = cnt[a[i]] = 0;
    FOR(i,1,num[0]){
        LL sum = r - l + 1;
        LL maxx = sum, minn = sum;
        FOr(j,l,mid){
            if(a[j] == num[i]) ++ sum;
            else -- sum;
            maxx = max(maxx, sum);
            minn = min(minn, sum);
            ++ cnt[sum];
        }
    if(a[mid] == num[i]) ++ sum;
    else -- sum;
    FOR(i,minn,maxx) cnt[i] += cnt[i-1];
    FOR(j,mid+1,r){
        if(a[j] == num[i]) ++ sum;
        else -- sum;
        ans += cnt[min(maxx,sum-1)];
    }
    FOR(i,minn,maxx) cnt[i] = 0;
    }
    num[0]=0;
}
/*----------- SOLVE CASES -----------*/
void solve(){
    cin >> n;
    FOR(i,1,n) cin >> a[i];
  
    ans = 0ll;
    work(1,n);
    cout << ans  << ENDL;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    unsigned _TvT_ = 1;
    cin >> _TvT_;
    SOLVE_CASES;
    return 0;
}