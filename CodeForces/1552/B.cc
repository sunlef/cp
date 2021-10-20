/***

    Filename:   B.cc
    Author:     CleanBlue
    Time:       2021-07-25 22:49:10 utc+8
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

const double EPS  = 1e-6;
const double PI   = acos(-1.0);
const int    INF  = 0x3f3f3f3f;
const LL     LINF = 0x3f3f3f3f3f3f3f3fLL;

/*---VARIABLES---*/ MAXN(50514) /*---VARIABLES---*/
int n;
struct Node{
    int a, b, c, d, e;
    bool operator < (const Node& B) const {
        int aa = 0, bb = 0;
        if(a < B.a) ++ aa;
        else ++bb;
        if(b < B.b) ++ aa;
        else ++bb;
        if(c < B.c) ++ aa;
        else ++bb;         
        if(d < B.d) ++ aa;
        else ++ bb;
        if(e < B.e) ++ aa;
        else ++ bb;
        return aa > bb;
    }
}a[SIZE];
vector< pair<Node, int> > v;
/*----------- SOLVE CASES -----------*/
void solve(){
    v.clear();
    cin >> n;
    FOR(i,1,n){
        int a,b,c,d,e;
        cin >> a >>b >> c >> d >> e;
        v.EB(MP((Node){a,b,c,d,e},i));
    }
    sort(v.begin(),v.end());

    if(n == 1) cout << 1 << ENDL;
    else{
        bool flag = true;
        FOr(i,2,n){
            int aa = (v[0].first.a < v[i].first.a) + 
                     (v[0].first.b < v[i].first.b) + 
                     (v[0].first.c < v[i].first.c) + 
                     (v[0].first.d < v[i].first.d) +
                     (v[0].first.e < v[i].first.e);
            if(aa < 3){
                flag = false;
                break;
            }
        }
        if(flag) cout << v[0].second << ENDL;
        else cout << -1 << ENDL;
    }

}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    unsigned _TvT_ = 1;
    cin >> _TvT_;
    SOLVE_CASES;
    return 0;
}   