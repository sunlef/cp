/***

    Filename:   e.cc
    Author:     CleanBlue
    Time:       2021-07-24 14:31:58 utc+8
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

void print(__int128 x)
{
    if(x < 0)
    {
        x = -x;
        putchar('-');
    }
     if(x > 9) print(x/10);
    putchar(x%10 + '0');
}
inline void read(__int128 &X)
{
	X = 0;
	int w=0; char ch=0;
	while(!isdigit(ch)) {w|=ch=='-';ch=getchar();}
	while(isdigit(ch)) X=(X<<3)+(X<<1)+(ch^48),ch=getchar();
	if (w) X = -X;
}

/*---VARIABLES---*/ MAXN(104514) /*---VARIABLES---*/
__int128 anspos[1100000];
struct Node{
    __int128 a, b, k;
    bool operator < (const Node &B) const {
        return a < B.a;
    }
};
vector<Node> v;
/*----------- SOLVE CASES -----------*/
void solve(){
    __int128 n;
    read(n);
    
    int pos = LB(anspos+1, anspos+v.size()+1, n) - anspos;
    if(anspos[pos] != n) --pos;
    cout << pos << ENDL;
}

int main(){

   // ios::sync_with_stdio(0); cin.tie(0);
    unsigned _TvT_;
    cin >> _TvT_;

    for(__int128 i = 1; i*i*i >= 1ll && i*i*i <= 1000000000000000000ll; ++i)
        v.EB((Node){i*i*i,i,i*i});
    for(int i = 0; i < v.size(); ++i){
        __int128 na = v[i].a * v[i].k  - v[i].b;
        __int128 nb = v[i].a;
        __int128 nk = v[i].k;
        if(na >= 1ll && na <= 1000000000000000000ll && nb >= 1ll && nk >= 1ll)
            v.EB((Node){na,nb,nk});
    }

    sort(v.begin(), v.end());
    FOr(i,0,v.size()) anspos[i+1] = v[i].a;

    SOLVE_CASES;
    return 0;
}