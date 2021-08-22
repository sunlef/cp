/***

    Filename:   t.cc
    Author:     CleanBlue
    Time:       2021-07-30 19:47:25 utc+8
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

/*---VARIABLES---*/ MAXN(114514) /*---VARIABLES---*/
int trie[SIZE][2], trie_cnt = 1;
void insert_trie(const bitset<3> &b){
    int p = 1;
    FOr(i,0,3){
        if(trie[p][b[i]] == 0) trie[p][b[i]] = ++trie_cnt;
        p = trie[p][b[i]];
    }
}

int search_trie(const bitset<3> &b){
    int p = 1;
    int res = 0;
    FOr(i,0,3){
        res <<= 1;
        if(trie[p][!b[i]]){
            res += 1;
            p = trie[p][!b[i]];
        }
        else{
            p = trie[p][b[i]];
        }
    }
    return res;
}
int N;
bitset<3> a[SIZE];
/*----------- SOLVE CASES -----------*/
void solve(){
    cin >> N;
    FOR(i,1,N){
        int x;
        cin >> x;
        a[i] = x;
        insert_trie(a[i]);
    }
    FOR(i,1,trie_cnt) cout << i << " " << trie[i][0] << " " << trie[i][1] << ENDL;
    int ans = -INF;
    FOR(i,1,N) ans = max(ans, search_trie(a[i]));
    cout << ans << ENDL;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    unsigned _TvT_ = 1;
    //cin >> _TvT_;
    SOLVE_CASES;
    return 0;
}