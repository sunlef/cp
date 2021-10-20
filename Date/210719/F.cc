/***

    Filename:   F.cc
    Author:     CleanBlue
    Time:       2021-07-19 20:43:38 utc+8
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

/*---VARIABLES---*/ MAXN(114514) /*---VARIABLES---*/
struct Node{
    double x, y, z;
}A, B, C, D, O1, O2;
double k1, k2, r1, r2, R;

void calc(Node &p1, Node &p2, double k, Node &o, double &R){
    double d = sqrt(
        (p1.x - p2.x)*(p1.x - p2.x)+
        (p1.y - p2.y)*(p1.y - p2.y)+
        (p1.z - p2.z)*(p1.z - p2.z)
    );
    double pos1 = k/(k+1), pos2 = k/(k-1);
    double mid = (pos1 + pos2) / 2;
    R = d * fabs(pos1 - pos2) / 2;
    o.x = p1.x + (p2.x - p1.x) * mid;
    o.y = p1.y + (p2.y - p1.y) * mid;
    o.z = p1.z + (p2.z - p1.z) * mid;
}

double V(double r, double h){
    return PI*(r - h)*r*r - PI*(r*r*r-h*h*h)/3;
}
/*----------- SOLVE CASES -----------*/
void solve(){
    cin >> A.x >> A.y >> A.z;
    cin >> B.x >> B.y >> B.z;
    cin >> C.x >> C.y >> C.z;
    cin >> D.x >> D.y >> D.z;
    cin >> k1 >> k2;
    calc(A,B,k1,O1,r1);
    calc(C,D,k2,O2,r2);

    R = sqrt(
        (O1.x - O2.x) * (O1.x - O2.x) + 
        (O1.y - O2.y) * (O1.y - O2.y) +
        (O1.z - O2.z) * (O1.z - O2.z)
    );

    if(r1 + r2 < R){
        cout << "0.000" << ENDL;
        return;
    }

    if(r1 + R < r2){
        printf("%.3lf\n", 4*PI*r1*r1*r1/3);
        return;
    }

    if(r2 + R < r1){
        printf("%.3lf\n", 4*PI*r2*r2*r2/3);
        return; 
    }

    double dr = sqrt(
        (r1+r2+R) * (r1+r2-R) * (r1-r2+R) * (r2+R-r1)
    ) / R / 2;
    double d1 = sqrt(r1*r1 - dr*dr);
    double d2 = sqrt(r2*r2 - dr*dr);
    double n1, n2;

    if(fabs(d1+d2-R) < EPS)
        n1 = d1, n2 = d2;
    else if(fabs(-d1+d2-R) < EPS)
        n1 = -d1, n2 = d2;
    else if(fabs(d1-d2-R) < EPS)
        n1 = d1, n2 = -d2;
    else
        n1 = -d1, n2 = -d2;

    double V1 = V(r1,n1), V2 = V(r2,n2);
    printf("%.3lf\n", V1 + V2);
}

int main(){
   // ios::sync_with_stdio(0); cin.tie(0);
    unsigned _TvT_ = 1;
    cin >> _TvT_;
    SOLVE_CASES;
    return 0;
}