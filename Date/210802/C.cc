/***

    Filename:   C.cc
    Author:     CleanBlue
    Time:       2021-08-03 00:23:24 utc+8
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
/*---VARIABLES---*/ MAXN(114514) /*---VARIABLES---*/
int trie[SIZE][26], trie_cnt = 1;
bool is_end[SIZE];

void insert_trie(string &str){
    int p = 1;
    for(auto &ch : str){
        int b = ch - 'a';
        if(trie[p][b] == 0) trie[p][b] = ++trie_cnt;
        p = trie[p][b];        
    }
    is_end[p] = true; 
}

bool search_trie(string &str){
    int p = 1;
    for(auto &ch : str){
        int b = ch - 'a';
        if(trie[p][b] == 0) return false;
        p = trie[p][b];
    }
    return is_end[p];
}

//梳妆数组
int t[MAXN];
inline int lowbit(int x) { return x & -x; }
void treeBuild()
{
    for(int i = 1; i <= n; ++i) {
        t[i] += a[i];
        int j = i + lowbit(i);
        if(j <= n) t[j] += t[i];
    }
}
void treeAdd(int x, int pos)
{
    while(pos <= n) {
        t[pos] += x;
        pos += lowbit(pos);
    }
}
int treeQuery(int pos)
{
    int res = 0;
    while(pos >= 1) {
        res += t[pos];
        pos -= lowbit(pos);
    }
    return res;
}

//冰茶几
int fa[SIZE], rk[SIZE];
void build_set(int l, int r) {FOR(i,l,r) fa[i] = i, rk[i] = 1;}

int getfa(int x) {return fa[x] == x ? x : fa[x] = getfa(fa[x]);}

void merge_set(int x, int y) {
   int u = getfa(x), v = getfa(y);
   if(rk[u] > rk[v]) fa[v] = u, rk[u] += rk[v];
   else fa[u] = v, rk[v] += rk[u];
}

/*----------- SOLVE CASES -----------*/
void solve(){

}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    unsigned _TvT_ = 1;
    //cin >> _TvT_;
    SOLVE_CASES;
    return 0;
}