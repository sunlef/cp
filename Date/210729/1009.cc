/***

    Filename:   1009.cc
    Author:     CleanBlue
    Time:       2021-07-29 12:17:47 utc+8
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
string s[31];
string s[2][121];
struct Node{
    int idx, w;
    int sti, stj;
    int edi, edj;
}cha[70];
bool check(int a, int b, int c){

}
/*----------- SOLVE CASES -----------*/
void solve(){
    cout << "Case #" << CASE_NUM << ":" << EDNL;
    FOR(i,1,30) cin >> str[i];
    FOR(i,1,30) str[i] = "." + str[i];
    int cnt = 0;
    int l = 1;
    while(cnt < 7){
        bool flag = false;
        if(cnt == 0){
            FOR(i,1,30){
                if(flag) break;
                FOR(j,l,100){
                    if(flag) break;
                    FOR(k,1,31){
                        if(check(i,j,k)){
                            flag = true;
                            cout << l << " " << l + cha[k].w - 1<< ENDL;
                            l = l + cha[k].w;
                            ++cnt;
                            break;
                        }
                    }
                }
            }
        }
        else{
            FOR(i,1,30){
                if(flag) break;
                FOR(j,l,100){
                    if(flag) break;
                    FOR(k,32,65){
                        if(check(i,j,k)){
                            flag = true;
                            cout << l << " " << l + cha[k].w - 1 << ENDL;
                            l += cha[k].w;
                            ++cnt;
                            break;
                        }
                    }
                }
            }
        }
    }
}

int main(){
    ios:sync_with_stdio(0); cin.tie(0);
    unsigned _TvT_ = 1;
    cin >> _TvT_;
    //==========//
    s[1][1] = s[1][2] = s[1][3] = s[1][79] = s[1][80] = 
    s[1][19] = s[1][20] = s[1][21] = s[1][22] = s[1][23] = 
    s[1][39] = s[1][40] = s[1][41] = s[1][42] = s[1][43] =
    s[1][59] = s[1][60] = s[1][61] = s[1][62] = s[1][63] =  "........................................................................................................................................................................................................";
    s[1][4] = "...............##............#.......#.............#..##..##......#############.........#.....#.......##........................#.............###########......#......##.............#.....#............";
    s[1][5] = "................##............##.#########....######..####..#.........#...#.........###############....##..##########...........#.............#....#....#.......##.....##........###############........";
    s[1][6] = ".........###############.......#.....#...#........##..#######......#..#...#..#..........#.....#.........#.........##.....###############......#.#..#..#.#........#......#............#.....#............";
    s[1][7] = ".....................................#...#....####.#...............##.#...#..#.......#############.......#.......##.............#.............#..#.#.#..#...........########.........#.....#............";
    s[1][8] = "...........###########......#...###########.....###########.........#.#...#.#........#...........#..............##..............#.............#.#..#.#..#...........#......#...........#................";
    s[1][9] = "...........#.........#......##.......#...#......#....#....#...........#...#..........#.#########.#.............##...............#.............###########.....##....#......#...........#................";
    s[1][10]= "...........#.........#.......##......#...#......###########......###############......................###......##.........#############............#............##..#......#......###########...........";
    s[1][11] ="...........#.........#........#..#########......#....#....#..........................#############......#......##............................#############..........########...........#....#...........";
    s[1][12] ="...........###########...............#..........###########........###########..........###....#........#......##..................................#................#......#.......#...#....##..........";
    s[1][13] ="................#..............#.#########........#.....#..........#.........#.......###..##..###.......#......##..........###########.............#.............#.##..............##.##....#.#.........";
    s[1][14] ="............#...#...#.........#......#.........#############.......#.........#......#...##.###..........#......##..........#.........#......###############.....##.##.............##..#.....#.##........";
    s[1][15] ="...........##...#...##........#......#............#.....#..........###########......#.##..###.#.........#......##..........#.........#..........................#..#.............##..##.....#..#........";
    s[1][16] ="...........#....#....##......##.###########...###############......#.........#.......#...##.#..#.......###...###...........#.........#........#..#..##..##.....##..#................##.....##...........";
    s[1][17] ="..........#.....#.....#......#.......#...........###...####........#.........#........####..#...##....##.##........##......#.........#.......#...#...#...#.....#..##...............##...#..##...........";
    s[1][18] =".........#...####.....##....##.......#........###..........##......###########......##....##.....##...#....#########.......###########......##...#...#....#...##.##..............##......###............";

    s[1][24] =".........##....#......##......##.....##........#...#########.......##.....#.............##............######..#..........####.####.#####....##....#..######.........##.............#.......#............";
    s[1][25] ="...........##..#..####........#.......#.........#..........#.....#######.######........#######............#..######......#..#.#..#.#..##.....##...#..##..##.....###########........#.......#............";
    s[1][26] ="............#..#..##..........#...#########......#.........#......#...#.###..#........##....##.........#.#...#...#.......#..#.#..#.#..#........#..#..##..##.....#.#..#..#.#........#...########.........";
    s[1][27] =".............#######........#####.#.......#..........#.....#......#...#....##........############.....####.##########....#..#.#..#.#..#...........#..##..##.....#..#.#.#..#......#####.....#............";
    s[1][28] =".........#.....#..##........##..#.#.......#....#.....#.....#.....##########..###....#.#....#....#.......##..#...#..##....####.####.#.#......#...#######..##.....###########........#.......#............";
    s[1][29] =".........##....#..######....##..#..#######.....#.#########.#..............#####.......###########........#..#...#..##..............#.#......##....#..######.....#..###.#..#........##......#............";
    s[1][30] ="...........#...#..##.##.....##..#..............#.##..#..##.#......######....#.........#....#....#.....###############.....#######..#.##......##..##..##..##.....###..#..#.#.......###.##########........"; 
    s[1][31] ="...............#####.##.....#####..............#.##..#..##.#......#....#########....###############.....#.#...##....#..............#..#..........###.##..##.....###########.......##.#..................";
    s[1][32] ="............#####.##.##.....##..#.#########....#.##..#..##.#......######................................#.####.##.##.....#########.#...#.........######..##.......................##.#.....#............";
    s[1][33] ="...........#.#.#..#..##.....##..#...##.#.......#.#########.#......#....#.######.......###########.......#.#.#..####........#.......#...#......#.#.#.#######...###############....#.#.......#............";
    s[1][34] ="...........#...#..#..##.....##..#...#..#.......#.....#..#..#......######.#....#.......##.......##.......#....##.#.#.......#######..#...#......#.#.#..##..##......#..............##.#...#########........";
    s[1][35] ="..........##...#..#..##.....#####...#..#.......#.....#..#..#........#....#..#.#.......###########.......#..##..#.#.#............#..#####.....#.#..#..##..##.....###########......#.#.......#............";
    s[1][36] ="..........#....#..#..##.....##.....##..#..#....#.....#####.#.....#######.#.#..#.......##.......##.......#....##..#.##...........#..#.........#.#..#..##..##...............#........#.......#............";
    s[1][37] =".........##....#.#...##.....##....##...#..#....#.#####...#.#........#.....#####.......##.......##.......#..##...#...#..........##..#........##....#..######..............##........#.......#............";
    s[1][38] =".........#...###.#...##..........#.....####....#..........##........#...##.....#......###########.....###.....###...........####...#........#.....#..##..##...........####.........#..##########........";
 
    s[1][44] = "..................##........##.......##.........#..........#............#.................................#.....#........#####.....#...........#.......#.............#.................##...............";
    s[1][45] = ".........#####.....#.........###....###.........#....#.....#.......###########........###########.....###############....#...#.....#...........#.......#.......#############............##..............";
    s[1][46] = "...........#...#########.......#...##.##........#....#.....#.......#....#....#............................#.....#.#......#..#..#########.......#.......#.............#............#############.........";
    s[1][47] = "...........#.....................##.....###.....#....#.....#.......###########..................................#..#.....#..#......#........###############.....###########.......#...........#........."; 
    s[1][48] = "...........#....#######.....#..##.#######.#.....#....#.....#............#.............................#..############....#.#....#..#..#........#.......#.............#............#...........#.........";
    s[1][49] = "...........#....#.....#.....##..................#....#.....#.....###############......................#..#......#........#.##...#..#.##........#.......#......###############...........................";
    s[1][50] = ".........#####..#.....#.......#..#####.#.#......#....#.....#........................###############...#..#.######..#.....#..#...#..#.#.........#.......#.........................###############........";
    s[1][51] = "...........#....#.....#..........#..##.#.#......#....#.....#.......###########...........##............###.#.#..##.#.....#...#..####.#.........#.......#........###########.............#...............";
    s[1][52] = "...........#....#######..........#####.#.#......#....#.....#.......##.......##...........#...............#.#####.###.....#...#.#########.......#########........##.......##.............#...............";
    s[1][53] = "...........#.......#..........#..#..##.#.#......#....#.....#.......##...#...##..........##....#.......####.#...#.##......#...#....##...........#.......#........###########.............#...............";
    s[1][54] = "...........#....#..#.##.......#..#..##.#.#.....##....#.....#.......##...#...##..........#.....##.......#.#.#####.##......#.##.....###..........#.......#........##.......##.............#...............";
    s[1][55] = "...........###.##..#..#......##..#####.#.#.....#.....#.....#.......##..##...##.........##......##......#.#.#.#...#.......#.......##.#..........#.......#........###########.............#...............";
    s[1][56] = ".........###...#...#..##.....#...#..##...#.....#.....#.....#..........##.###...........#........#......#.#.########.#....#......##...#.........#.......#........##.......##.............#...............";
    s[1][57] = "..............#.#..#...#....##...#..##...#....##.....#.....#........###.....####......##...#######....#.#..#...##.#.#....#.....##....##........#########........##.......##.............#...............";
    s[1][58] = ".................###........#....#.##..###....#............#.....###..........#......#######.....##...#.#.....##...##....#...##........#.......#.......#........##.....###...........####...............";
  
    s[1][64] = "............#........###................................................................................................................................................................................";
    s[1][65] = ".........#############..................................................................................................................................................................................";
    s[1][66] = "..........#...##.##.....................................................................................................................................................................................";
    s[1][67] = "...........#..#..##.....................................................................................................................................................................................";
    s[1][68] = "...........#..#..##.....................................................................................................................................................................................";
    s[1][69] = ".........##########.....................................................................................................................................................................................";
    s[1][70] = "............#....#######................................................................................................................................................................................";
    s[1][71] = "............#....##..#..................................................................................................................................................................................";
    s[1][72] = ".........##########..#..................................................................................................................................................................................";
    s[1][73] = "............#....##..#..................................................................................................................................................................................";
    s[1][74] = "..........#.#.##.#...#..................................................................................................................................................................................";
    s[1][75] = "..........#.#..#.#...#..................................................................................................................................................................................";
    s[1][76] = ".........#..#..#.#...#..................................................................................................................................................................................";
    s[1][77] = "............#...##...#..................................................................................................................................................................................";
    s[1][78] = "...........##...#....#..................................................................................................................................................................................";
   
    s[2][1] = s[2][2] = s[2][3] = s[2][4] = s[2][5] = s[2][6] = s[2][7] = 
    s[2][25] = s[2][26] = s[2][27] = s[2][28] = s[2][29] = s[2][30] = s[2][31] = s[2][32] = s[2][33] = s[2][34] = s[2][35] = s[2][36] = s[2][37] =
    s[2][55] = s[2][56] = s[2][57] = s[2][58] = s[2][59] = s[2][60] = s[2][61] = s[2][62] = s[2][63] = s[2][64] = s[2][65] = s[2][66] = s[2][67] =
    s[2][85] = s[2][86] = s[2][87] = s[2][88] = s[2][89] = s[2][90] = s[2][91] = s[2][92] = s[2][93] = s[2][94] = s[2][95] = s[2][96] = s[2][97] =
    "....................................................................................................................................................................................";

    s[0][8]  = ".................#####............##............#####.........########............##.........########............#..........#########........#####..........######..................";
    s[0][9]  = "................######............##...........#######........########...........###.........########...........##..........#########.......##...##.........##..###.................";
    s[0][10] = "...............##....##...........##..........##....##.............###...........###.........##................##..................#.......##.....#........##....##.................";
    s[0][11] = "...............##....##...........##.................##...........###...........####.........##...............###.................##.......##.....#........##.....##................";
    s[0][12] = "...............##.....#...........##................##...........###............####.........##...............##..................##.......##.....#........##.....##................";
    s[0][13] = "...............##.....#...........##................##..........###.............####.........##..............##..................##........##....##........##.....##................";
    s[0][14] = "...............##.....#...........##................##..........#####..........#####.........#######.........##..................##.........##..###........##....##.................";
    s[0][15] = "...............##.....#...........##...............##...........######.........##.##.........########........#####...............#...........#####..........#######.................";
    s[0][16] = "...............##.....#...........##..............###...............##........###.##...............###......#######.............##..........#######..........######.................";
    s[0][17] = "...............##.....#...........##.............###................##........##..##................##......###...##............##.........##....##.............###.................";
    s[0][18] = "...............##.....#...........##.............##.................##........##..##................##......##....##............##.........##.....##............##..................";
    s[0][19] = "...............##.....#...........##............###.................##.......##...##................##......##.....##..........##..........##.....##...........###..................";
    s[0][20] = "...............##.....#...........##...........###............##....##.......#########..............##......##.....##..........##..........##.....##...........##...................";
    s[0][21] = "...............##....##...........##...........##.............##....##.......#########.......##.....##......##.....##..........##..........##.....##..........##....................";
    s[0][22] = "...............##....##...........##..........###.............###...##............##..........##...###......###...##...........##..........###..###..........###....................";
    s[0][23] = "................######............##..........########.........######.............##..........#######........#######...........##...........######..........###.....................";
    s[0][24] = ".................####.............##..........########..........####..............##...........#####..........####.............##.............###...................................";0
 
    s[0][38] = "..................##...........#######..........#####.........#######........########.........#######.........#####.........##.....##.............##.......##....##.................";
    s[0][39] = "..................###..........##....##........##..###........#....###.......##...............##.............##...##........##.....##.............##.......##...##..................";
    s[0][40] = "..................###..........##.....#.......##.....##.......#......#.......##...............##............##.....##.......##.....##.............##.......##...##..................";
    s[0][41] = ".................####..........##.....#.......##.....##.......#......##......##...............##............##.....##.......##.....##.............##.......##..##...................";
    s[0][42] = ".................####..........##.....#.......##..............#......##......##...............##............##..............##.....##.............##.......##.###...................";
    s[0][43] = ".................##.#..........##....##.......##..............#......##......##...............##............##..............##.....##.............##.......##.###...................";
    s[0][44] = ".................##.##.........########.......##..............#......##......##...............##............##..............##.....##.............##.......######...................";
    s[0][45] = ".................##.##.........#######........##..............#......##......#######..........######........##.######.......#########.............##.......######...................";
    s[0][46] = "................###.##.........##...###.......##..............#......##......##...............##............##.######.......##.....##.............##.......###..##..................";
    s[0][47] = "................##..##.........##....##.......##..............#......##......##...............##............##.....##.......##.....##.............##.......###..##..................";
    s[0][48] = "................##...#.........##.....#.......##..............#......##......##...............##............##.....##.......##.....##.............##.......##...##..................";
    s[0][49] = "................##...##........##.....#.......##..............#......##......##...............##............##.....##.......##.....##.............##.......##....#..................";
    s[0][50] = "................#######........##.....#.......##.....##.......#......##......##...............##............##.....##.......##.....##......##.....##.......##....##.................";
    s[0][51] = "...............########........##....##.......##.....##.......#......#.......##...............##............##.....##.......##.....##......##.....##.......##....##.................";
    s[0][52] = "...............##....##........##....##.......###...##........#.....##.......##...............##............###...##........##.....##......###...##........##....##.................";
    s[0][53] = "...............##....##........#######.........######.........#######........########.........##.............######.........##.....##.......######.........##.....##................";
    s[0][54] = "...............##.....##.......######............###..........######.........########.........##...............###..........##.....##.........###..........##.....##................";0
   
    s[0][68] = "...............##..............##....###......##.....##.......#######..........#####.........#######..........#####.........#########......##.....##.......##.....##................";
    s[0][69] = "...............##..............###...###......##.....##.......##....##........##..###........##....##........###.###...........##..........##.....##.......##....##.................";
    s[0][70] = "...............##..............###..####......###....##.......##.....##......##.....##.......##.....##......##....##...........##..........##.....##........#....##.................";
    s[0][71] = "...............##..............####.####......###....##.......##.....##......##.....##.......##.....##......##.....##..........##..........##.....##........##...##.................";
    s[0][72] = "...............##..............######.##......####...##.......##.....##......##.....##.......##.....##......##.................##..........##.....##........##...##.................";
    s[0][73] = "...............##..............##.##..##......####...##.......##.....##......##.....##.......##.....##......##.................##..........##.....##........##...##.................";
    s[0][74] = "...............##..............##..#..##......##.##..##.......##....##.......##.....##.......##....##.......###................##..........##.....##........##..##..................";
    s[0][75] = "...............##..............##.....##......##.##..##.......########.......##.....##.......########........#####.............##..........##.....##.........#..##..................";
    s[0][76] = "...............##..............##.....##......##.##..##.......#######........##.....##.......#######..........#####............##..........##.....##.........##.##..................";
    s[0][77] = "...............##..............##.....##......##..##.##.......##.............##.....##.......##..##...............##...........##..........##.....##.........##.##..................";
    s[0][78] = "...............##..............##.....##......##..##.##.......##.............##.....##.......##..##................##..........##..........##.....##.........##.##..................";
    s[0][79] = "...............##..............##.....##......##...####.......##.............##.....##.......##...##...............##..........##..........##.....##.........####...................";
    s[0][80] = "...............##..............##.....##......##...####.......##.............##..##.##.......##...##...............##..........##..........##.....##..........###...................";
    s[0][81] = "...............##..............##.....##......##....###.......##.............##...####.......##....##.......##.....#...........##..........##.....##..........###...................";
    s[0][82] = "...............##..............##.....##......##....###.......##..............##..###........##....##........##...##...........##..........###...##...........###...................";
    s[0][83] = "...............#########.......##.....##......##....###.......##..............#######........##....##........######............##...........######............##....................";
    s[0][84] = "...............#########.......##.....##......##.....##.......##................#####........##.....##.........###.............##.............###.............##....................";

    s[0][98]  = "...............#......##.......##....##.......##....##........#########.............................................................................................................";
    s[0][99]  = "...............#...#..##.......###...##........##...##..............###.............................................................................................................";
    s[0][100] = "...............#...#..##........##...##........##..##...............##..............................................................................................................";
    s[0][101] = "...............#...#..##........##..##..........##.##..............###..............................................................................................................";
    s[0][102] = "...............##.##..#..........##.##..........####...............##...............................................................................................................";
    s[0][103] = "...............##.##..#..........####............###..............###...............................................................................................................";
    s[0][104] = "...............##.##..#...........###............##...............##................................................................................................................";
    s[0][105] = "................#.#####...........###............##..............###................................................................................................................";
    s[0][106] = "................#.#####...........###............##..............##.................................................................................................................";
    s[0][107] = "................#.#####...........###............##.............###.................................................................................................................";
    s[0][108] = "................#######..........####............##.............##..................................................................................................................";
    s[0][109] = "................###.##...........##.##...........##............###..................................................................................................................";
    s[0][110] = "................###.##..........###.##...........##............##...................................................................................................................";
    s[0][111] = "................###.##..........##...##..........##...........###...................................................................................................................";
    s[0][112] = ".................#..##..........##...##..........##...........##....................................................................................................................";
    s[0][113] = ".................#..##.........##....##..........##...........#########.............................................................................................................";
    s[0][114] = ".................#..##.........##.....##.........##...........#########.............................................................................................................";

    cha[1].idx = 1; cha[1].sti = 4; cha[1].stj = 9; cha[1].edi = 18; cha[1].edj = 23; cha[1].w = cha[1].edj - cha[1].stj + 1;
    cha[2].idx = 1; cha[2].sti = 4; cha[2].stj = 28; cha[2].edi = 18; cha[2].edj = 43;
    cha[3].idx = 1; cha[3].sti = 4; cha[3].stj = 46; cha[3].edi = 18; cha[3].edj = 60;
    cha[1].idx = 1; cha[1].sti = 4; cha[1].stj = 65; cha[1].edi = 18; cha[1].edj = 79;
    cha[1].idx = 1; cha[1].sti = 4; cha[1].stj = 74; cha[1].edi = 18; cha[1].edj = 88;
    cha[1].idx = 1; cha[1].sti = 4; cha[1].stj = 92; cha[1].edi = 18; cha[1].edj = 106;
    cha[1].idx = 1; cha[1].sti = 4; cha[1].stj = 111; cha[1].edi = 18; cha[1].edj = 125;
    cha[1].idx = 1; cha[1].sti = 4; cha[1].stj = 130; cha[1].edi = 18; cha[1].edj = 144;
    cha[1].idx = 1; cha[1].sti = 4; cha[1].stj = 148; cha[1].edi = 18; cha[1].edj = 23;
    cha[1].idx = 1; cha[1].sti = 4; cha[1].stj = 9; cha[1].edi = 18; cha[1].edj = 23;



    //==========//
    SOLVE_CASES;
    return 0;
}