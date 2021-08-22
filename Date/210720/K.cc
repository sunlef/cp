/***

    Filename:   K.cc
    Author:     CleanBlue
    Time:       2021-07-21 00:41:18 utc+8
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

/*---VARIABLES---*/ MAXN(1002) /*---VARIABLES---*/
int n, m;
char a[SIZE][SIZE];
char ans[SIZE][SIZE];
int u[SIZE][SIZE], l[SIZE], r[SIZE];

map<char, PII> mp;
set<char> visted;

bool check(int x, int UL, int DR, bool t){ //t = true: 先纵向拓展
                                        //t = false: 先横向拓展
    if(t){
        FOR(i,UL,DR) if(ans[i][x] != '.') return false;
        return true;
    }
    else{
        FOR(j,UL,DR) if(ans[x][j] != '.') return false;
        return true; 
    }
}

void draw(char ch, bool t){//t = true: 先纵向拓展
                          //t = false: 先横向拓展
    int U,D,L,R;
    U = D = mp[ch].first, L = R = mp[ch].second;

    if(t){
        while(U-1 >= 1 && ans[U-1][mp[ch].second] == '.') --U;
        while(D+1 <= n && ans[D+1][mp[ch].second] == '.') ++D;
        while(L-1 >= 1 && check(L-1,U,D,t))              --L;
        while(R+1 <= m && check(R+1,U,D,t))              ++R;

        FOR(i,U,D) FOR(j,L,R) ans[i][j] = tolower(ch);
        ans[mp[ch].first][mp[ch].second] = ch;
    }
    else{
        while(L-1 >= 1 && ans[mp[ch].first][L-1] == '.') --L;
        while(R+1 <= m && ans[mp[ch].first][R+1] == '.') ++R;
        while(U-1 >= 1 && check(U-1,L,R,t))             --U;
        while(D+1 <= n && check(D+1,L,R,t))             ++D;

        FOR(i,U,D) FOR(j,L,R) ans[i][j] = tolower(ch);
        ans[mp[ch].first][mp[ch].second] = ch;
    }
}

/*----------- SOLVE CASES -----------*/
void solve(){
    cin >> n >> m;

    FOR(i,1,n) FOR(j,1,m){
        cin >> a[i][j];
        if(a[i][j] != '.') mp[a[i][j]] = MP(i,j);
    }

    FOR(i,1,n) FOR(j,1,m){
        if(i == 1) u[i][j] = 1;
        if(a[i][j] != '.' && a[i][j] != 'A') u[i][j] = INF;
        if(i > 1 && (a[i][j] == '.' || a[i][j] == 'A')){
            if(u[i-1][j] == INF) u[i][j] = i;
            if(a[i-1][j] == '.' || a[i-1][j] == 'A') u[i][j] = u[i-1][j];
        }
    }

    int S = 0;
    int U, D, L, R;

    FOR(i,mp['A'].first,n){ // 悬线
        if(u[i][mp['A'].second] == INF) break;
        FOR(j,1,m) l[j] = r[j] = j;
        FOR(j,1,m){
            int posl = j-1;
            while(posl >= 1 && u[i][j] >= u[i][posl]) posl = l[posl] - 1;
            l[j] = posl + 1;
        }
        DEC(j,m,1){
            int posr = j+1;
            while(posr <= m && u[i][j] >= u[i][posr]) posr = r[posr] + 1;
            r[j] = posr - 1;
        }
        FOR(j,1,m){
            if(u[i][j] == INF || u[i][j] > mp['A'].first || l[j] > mp['A'].second || r[j] < mp['A'].second) continue;
            int nows = (i - u[i][j] + 1) * (r[j] - l[j] + 1);
            if(nows > S){
                S = nows;
                U = u[i][j], D = i, L = l[j], R = r[j];
            }
        }
    }

    FOR(i,U,D) FOR(j,L,R) a[i][j] = 'a';
    a[mp['A'].first][mp['A'].second] = 'A';

    FOR(i,1,n) FOR(j,1,m) ans[i][j] = a[i][j];
    visted.insert('A');
    FOR(i,1,n) FOR(j,1,m) if(ans[i][j] != '.' && !visted.count(toupper(ans[i][j]))){
        draw(ans[i][j], true);
        visted.insert(ans[i][j]);
    } 

    bool flag = true;
    FOR(i,1,n) FOR(j,1,m) if(ans[i][j] == '.') {flag = false; break;}

    if(flag) FOR(i,1,n) {FOR(j,1,m) cout << ans[i][j]; cout << ENDL;}

    else{
        visted.clear(); visted.insert('A');

        FOR(i,1,n) FOR(j,1,m) ans[i][j] = a[i][j];
        FOR(i,1,n) FOR(j,1,m) if(ans[i][j] != '.' && !visted.count(toupper(ans[i][j]))){
            draw(ans[i][j], false);
            visted.insert(ans[i][j]);
        }
        FOR(i,1,n) {FOR(j,1,m) cout << ans[i][j]; cout << ENDL;}
    }
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    unsigned _TvT_ = 1;
    //cin >> _TvT_;
    SOLVE_CASES;
    return 0;
}
