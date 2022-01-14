/***

    Filename:   CRC Test.cc
    Author:     CleanBlue
    Time:       2021-07-12 19:18:19 utc+8
    Site:       cleanblue.moe

***/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define ENDL '\n'
#define SIZE MAXN
#define DIV  cout << "\n==============================\n"

using namespace std;
typedef long long LoveLive;
typedef long double LD;
typedef unsigned long long ULL;
typedef LoveLive LL;
typedef pair<int, int> PII;
typedef pair<LoveLive, int> PLI;
typedef pair<LoveLive, LoveLive> PLL;

//const double PI = acos(-1.0);
//const double EPS = 1e-6;
//const int INF = 0x3f3f3f3f;
const int MAXN = 114514;

string p;
string x;
map<char, string> mp;
int a[35], b[16010];

void solve()
{
	cin >> p >> x;

	int pos = 0;
	for (int i = 0; i < p.size(); ++i)
		if (p[i] != '0') {
			pos = i;
			break;
		}

	int lena = p.size(), lenb = 4 * x.size();
	string s = p.substr(pos, lena - pos);
	int lens = s.size();

	for (int i = 0; i < s.size(); ++i)
		a[i] = s[i] - '0';
	for (int i = 0; i <= lena; ++i)
		b[lenb + i] = 0;
	for (int i = 0; i < x.size(); ++i)
		for (int j = 4 * i, k = 0; k < 4; ++j, ++k)
			b[j] = mp[x[i]][k] - '0';

	for (int i = 0; i < lenb; ++i)
		if (b[i] == 1)
			for (int j = 0; j < lens; j++)
				b[i + j] ^= a[j];

	for (int i = 0; i < lena - 1; ++i)
		cout << b[lenb + i];
	cout << ENDL;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	mp['0'] = "0000";
	mp['1'] = "0001";
	mp['2'] = "0010";
	mp['3'] = "0011";
	mp['4'] = "0100";
	mp['5'] = "0101";
	mp['6'] = "0110";
	mp['7'] = "0111";
	mp['8'] = "1000";
	mp['9'] = "1001";
	mp['A'] = "1010";
	mp['B'] = "1011";
	mp['C'] = "1100";
	mp['D'] = "1101";
	mp['E'] = "1110";
	mp['F'] = "1111";

	int T = 1;
	cin >> T;
	while (T--)
		solve();

	return 0;
}