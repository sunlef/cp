/***

    Filename:   P2580.cc
    Author:     CleanBlue
    Time:       2021-08-04 18:48:35 utc+8
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
int n;
int m;
struct trie{
    int S;
    int cnt = 0;
    std::vector<std::vector<int> > son;
    std::vector<bool> end;
    std::vector<int> visted;    
    trie(int n, int bit, int S) : S(S), son(n*bit+1, std::vector<int>(S, 0)), end(n*bit+1, false), visted(n*bit+1, 0) {}
    trie(int S) : S(S), son(SIZE, std::vector<int>(S, 0)), end(SIZE, false) {}
    trie(int size, int S) : S(S), son(size+1, std::vector<int>(S, 0)), end(size, false) {} 
    void insert(const string &str) {
        int p = 0;
        for(auto &ch : str) {
            int b = ch - 'a';
            if(son[p][b] == 0) son[p][b] = ++cnt;
            p = son[p][b];
        }
        end[p] = true;
    }
    int find(const string &str) {
        int p = 0;
        for(auto &ch : str) {
            int b = ch - 'a';
            if(son[p][b] == 0) return 0;
            p = son[p][b];
        }
        if(!end[p]) return 0;
        else return ++visted[p];
    }
}; 
/*----------- SOLVE CASES -----------*/
void solve(){
    cin >> n;
    trie tr(n, 50, 26);
    FOR(i,1,n){
        string s;
        cin >> s;
        tr.insert(s);
    }
    cin >> m;
    FOR(i,1,m){
        string s;
        cin >> s;
        int p = tr.find(s);
        if(p == 0) cout << "WRONG" << ENDL;
        else if(p == 1) cout << "OK" << ENDL;
        else cout << "REPEAT" << ENDL;
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    unsigned _TvT_ = 1;
    //cin >> _TvT_;
    SOLVE_CASES;
    return 0;
}