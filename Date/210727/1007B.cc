/***

    Filename:   1007B.cc
    Author:     CleanBlue
    Time:       2021-07-27 15:30:03 utc+8
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
struct Node{
    int m, a, b, c;
}a[SIZE], pre[SIZE];
int t[SIZE];
int l[SIZE];
int n, q;
string s;
map<int, string> mp;
void sti(int &a, int &b, int &c){
    int res = 0;
    if(s[5] >= '0' && s[5] <= '9') res += s[5] - '0';
    else res += 10 + s[5] - 'A';
    if(s[4] >= '0' && s[4] <= '9') res += 16 * (s[4] - '0');
    else res += 16 * (10 + s[4] - 'A');
    c = res;

    res = 0;
    if(s[3] >= '0' && s[3] <= '9') res += s[3] - '0';
    else res += 10 + s[3] - 'A';
    if(s[2] >= '0' && s[2] <= '9') res += 16 * (s[2] - '0');
    else res += 16 * (10 + s[2] - 'A');
    b = res;

    res = 0;
    if(s[1] >= '0' && s[1] <= '9') res += s[1] - '0';
    else res += 10 + s[1] - 'A';
    if(s[0] >= '0' && s[0] <= '9') res += 16 * (s[0] - '0');
    else res += 16 * (10 + s[0] - 'A');
    a = res;
}
/*----------- SOLVE CASES -----------*/
void solve(){
    cin >> n >> q;
    int idx = 1;
    t[0] = l[0] = 1;
    FOR(i,1,n){
        cin >> a[i].m;
        if(a[i].m == 1){
            t[i] = ++idx;
            l[i] = i;
        }
        else{
            t[i] = idx;
            l[i] = l[i-1];
        }
        cin >> s;
        sti(a[i].a, a[i].b, a[i].c);
    }
    pre[0].a = pre[0].b = pre[0].c = 0;
    FOR(i,1,n) pre[i].a = pre[i-1].a + a[i].a,
               pre[i].b = pre[i-1].b + a[i].b,
               pre[i].c = pre[i-1].c + a[i].c;
    
    FOR(i,1,q){
        int ll, r;
        cin >> ll >> r;
        int a = 0, b = 0, c = 0;

        if(t[ll] != t[r]) ll = l[r];
        a = pre[r].a - pre[ll-1].a;
        b = pre[r].b - pre[ll-1].b;
        c = pre[r].c - pre[ll-1].c;
        a = min(a, 255), b = min(b, 255), c = min(c, 255);

        cout << mp[a] << mp[b] << mp[c] << ENDL;
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    mp[0] = "00";
    mp[1] = "01";
    mp[2] = "02";
    mp[3] = "03";
    mp[4] = "04";
    mp[5] = "05";
    mp[6] = "06";
    mp[7] = "07";
    mp[8] = "08";
    mp[9] = "09";
    mp[10] = "0A";
    mp[11] = "0B";
    mp[12] = "0C";
    mp[13] = "0D";
    mp[14] = "0E";
    mp[15] = "0F";
    mp[16] = "10";
    mp[17] = "11";
    mp[18] = "12";
    mp[19] = "13";
    mp[20] = "14";
    mp[21] = "15";
    mp[22] = "16";
    mp[23] = "17";
    mp[24] = "18";
    mp[25] = "19";
    mp[26] = "1A";
    mp[27] = "1B";
    mp[28] = "1C";
    mp[29] = "1D";
    mp[30] = "1E";
    mp[31] = "1F";
    mp[32] = "20";
    mp[33] = "21";
    mp[34] = "22";
    mp[35] = "23";
    mp[36] = "24";
    mp[37] = "25";
    mp[38] = "26";
    mp[39] = "27";
    mp[40] = "28";
    mp[41] = "29";
    mp[42] = "2A";
    mp[43] = "2B";
    mp[44] = "2C";
    mp[45] = "2D";
    mp[46] = "2E";
    mp[47] = "2F";
    mp[48] = "30";
    mp[49] = "31";
    mp[50] = "32";
    mp[51] = "33";
    mp[52] = "34";
    mp[53] = "35";
    mp[54] = "36";
    mp[55] = "37";
    mp[56] = "38";
    mp[57] = "39";
    mp[58] = "3A";
    mp[59] = "3B";
    mp[60] = "3C";
    mp[61] = "3D";
    mp[62] = "3E";
    mp[63] = "3F";
    mp[64] = "40";
    mp[65] = "41";
    mp[66] = "42";
    mp[67] = "43";
    mp[68] = "44";
    mp[69] = "45";
    mp[70] = "46";
    mp[71] = "47";
    mp[72] = "48";
    mp[73] = "49";
    mp[74] = "4A";
    mp[75] = "4B";
    mp[76] = "4C";
    mp[77] = "4D";
    mp[78] = "4E";
    mp[79] = "4F";
    mp[80] = "50";
    mp[81] = "51";
    mp[82] = "52";
    mp[83] = "53";
    mp[84] = "54";
    mp[85] = "55";
    mp[86] = "56";
    mp[87] = "57";
    mp[88] = "58";
    mp[89] = "59";
    mp[90] = "5A";
    mp[91] = "5B";
    mp[92] = "5C";
    mp[93] = "5D";
    mp[94] = "5E";
    mp[95] = "5F";
    mp[96] = "60";
    mp[97] = "61";
    mp[98] = "62";
    mp[99] = "63";
    mp[100] = "64";
    mp[101] = "65";
    mp[102] = "66";
    mp[103] = "67";
    mp[104] = "68";
    mp[105] = "69";
    mp[106] = "6A";
    mp[107] = "6B";
    mp[108] = "6C";
    mp[109] = "6D";
    mp[110] = "6E";
    mp[111] = "6F";
    mp[112] = "70";
    mp[113] = "71";
    mp[114] = "72";
    mp[115] = "73";
    mp[116] = "74";
    mp[117] = "75";
    mp[118] = "76";
    mp[119] = "77";
    mp[120] = "78";
    mp[121] = "79";
    mp[122] = "7A";
    mp[123] = "7B";
    mp[124] = "7C";
    mp[125] = "7D";
    mp[126] = "7E";
    mp[127] = "7F";
    mp[128] = "80";
    mp[129] = "81";
    mp[130] = "82";
    mp[131] = "83";
    mp[132] = "84";
    mp[133] = "85";
    mp[134] = "86";
    mp[135] = "87";
    mp[136] = "88";
    mp[137] = "89";
    mp[138] = "8A";
    mp[139] = "8B";
    mp[140] = "8C";
    mp[141] = "8D";
    mp[142] = "8E";
    mp[143] = "8F";
    mp[144] = "90";
    mp[145] = "91";
    mp[146] = "92";
    mp[147] = "93";
    mp[148] = "94";
    mp[149] = "95";
    mp[150] = "96";
    mp[151] = "97";
    mp[152] = "98";
    mp[153] = "99";
    mp[154] = "9A";
    mp[155] = "9B";
    mp[156] = "9C";
    mp[157] = "9D";
    mp[158] = "9E";
    mp[159] = "9F";
    mp[160] = "A0";
    mp[161] = "A1";
    mp[162] = "A2";
    mp[163] = "A3";
    mp[164] = "A4";
    mp[165] = "A5";
    mp[166] = "A6";
    mp[167] = "A7";
    mp[168] = "A8";
    mp[169] = "A9";
    mp[170] = "AA";
    mp[171] = "AB";
    mp[172] = "AC";
    mp[173] = "AD";
    mp[174] = "AE";
    mp[175] = "AF";
    mp[176] = "B0";
    mp[177] = "B1";
    mp[178] = "B2";
    mp[179] = "B3";
    mp[180] = "B4";
    mp[181] = "B5";
    mp[182] = "B6";
    mp[183] = "B7";
    mp[184] = "B8";
    mp[185] = "B9";
    mp[186] = "BA";
    mp[187] = "BB";
    mp[188] = "BC";
    mp[189] = "BD";
    mp[190] = "BE";
    mp[191] = "BF";
    mp[192] = "C0";
    mp[193] = "C1";
    mp[194] = "C2";
    mp[195] = "C3";
    mp[196] = "C4";
    mp[197] = "C5";
    mp[198] = "C6";
    mp[199] = "C7";
    mp[200] = "C8";
    mp[201] = "C9";
    mp[202] = "CA";
    mp[203] = "CB";
    mp[204] = "CC";
    mp[205] = "CD";
    mp[206] = "CE";
    mp[207] = "CF";
    mp[208] = "D0";
    mp[209] = "D1";
    mp[210] = "D2";
    mp[211] = "D3";
    mp[212] = "D4";
    mp[213] = "D5";
    mp[214] = "D6";
    mp[215] = "D7";
    mp[216] = "D8";
    mp[217] = "D9";
    mp[218] = "DA";
    mp[219] = "DB";
    mp[220] = "DC";
    mp[221] = "DD";
    mp[222] = "DE";
    mp[223] = "DF";
    mp[224] = "E0";
    mp[225] = "E1";
    mp[226] = "E2";
    mp[227] = "E3";
    mp[228] = "E4";
    mp[229] = "E5";
    mp[230] = "E6";
    mp[231] = "E7";
    mp[232] = "E8";
    mp[233] = "E9";
    mp[234] = "EA";
    mp[235] = "EB";
    mp[236] = "EC";
    mp[237] = "ED";
    mp[238] = "EE";
    mp[239] = "EF";
    mp[240] = "F0";
    mp[241] = "F1";
    mp[242] = "F2";
    mp[243] = "F3";
    mp[244] = "F4";
    mp[245] = "F5";
    mp[246] = "F6";
    mp[247] = "F7";
    mp[248] = "F8";
    mp[249] = "F9";
    mp[250] = "FA";
    mp[251] = "FB";
    mp[252] = "FC";
    mp[253] = "FD";
    mp[254] = "FE";
    mp[255] = "FF";
    unsigned _TvT_ = 1;
    cin >> _TvT_;
    SOLVE_CASES;
    return 0;
}