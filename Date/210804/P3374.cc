/***

    Filename:   P3374.cc
    Author:     CleanBlue
    Time:       2021-08-04 18:38:41 utc+8
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
#define MP  make_pair
#define LB  lower_bound
#define UB  upper_bound
#define EB  emplace_back
#define PQ  priority_queue
#define DIV cout << "=====\n"

#define AUTO(A, B)   for (auto A : (B)
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
template <typename T>
struct BinaryIndexedTree { //梳妆数组
    int n;
    std::array<T> c;
    BinaryIndexedTree(int n) : n(n+1), c(n+1) {}
    void add(int pos, T val) {
        for(; pos < n; pos += pos & -pos) { c[pos] += val; }
    }
    T query(int pos) {
        T res = 0;
        for(; pos; pos -= pos & -pos) res += c[pos];
        return res;
    }
};
int n,m ;
/*----------- SOLVE CASES -----------*/
void solve(){
    cin >> n >> m;
    BinaryIndexedTree<LL> tr(n);
    FOR(i,1,n){ LL x; cin >> x; tr.add(i,x); }
    FOR(i,1,m){
        LL op, x, y;
        cin >> op >> x >> y;
        if(op == 1) tr.add(x,y);
        else cout << tr.query(y) - tr.query(x - 1) << ENDL;
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    unsigned _TvT_ = 1;
    //cin >> _TvT_;
    SOLVE_CASES;
    return 0;
}