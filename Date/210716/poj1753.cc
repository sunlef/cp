/***

    Filename:   poj1753.cc
    Author:     CleanBlue
    Time:       2021-07-16 16:42:47 utc+8
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
#define PUB  push_back
#define DIV  cout << "\n==============================\n"

using namespace std;
typedef long long LoveLive;
typedef long double LD;
typedef unsigned long long ULL;
typedef LoveLive LL;
typedef pair<int, int> PII;
typedef pair<LoveLive, int> PLI;
typedef pair<LoveLive, LoveLive> PLL;
typedef vector<int> VI;
typedef vector<LoveLive> VLL;

//const double PI = acos(-1.0);
//const double EPS = 1e-6;
const int INF = 0x3f3f3f3f;
const int MAXN = 114514;

char ori[5][5];
char f[5][5];
int ans;

bool check()
{
	char ch = f[1][1];
	for (int i = 1; i <= 4; ++i)
		for (int j = 1; j <= 4; ++j)
			if (f[i][j] != ch)
				return false;
	return true;
}

void cp()
{
	for (int i = 1; i <= 4; ++i)
		for (int j = 1; j <= 4; ++j)
			f[i][j] = ori[i][j];
}

map<char, char> mp;

void flip(int x, int y)
{
	f[x][y] = mp[f[x][y]];
	if (x - 1 >= 1)
		f[x - 1][y] = mp[f[x - 1][y]];
	if (x + 1 <= 4)
		f[x + 1][y] = mp[f[x + 1][y]];
	if (y - 1 >= 1)
		f[x][y - 1] = mp[f[x][y - 1]];
	if (y + 1 <= 4)
		f[x][y + 1] = mp[f[x][y + 1]];
}

char now;
void work(int x)
{
	int cnt = 0;
	for (int i = 0; i < 4; ++i) {
		if ((x << i) & 1) {
			flip(1, i + 1);
			++cnt;
		}
	}

	for (int i = 2; i <= 4; ++i)
		for (int j = 1; j <= 4; ++j) {
			if (f[i - 1][j] != now) {
				++cnt;
				flip(i, j);
			}
		}

	if (check())
		ans = min(ans, cnt);
}

void solve()
{
	for (int i = 1; i <= 4; ++i)
		for (int j = 1; j <= 4; ++j)
			cin >> ori[i][j];

	ans = INF;

	now = 'w';
	for (int i = 0; i < 16; ++i) {
		cp();
		work(i);
	}
	now = 'b';
	for (int i = 0; i < 16; ++i) {
		cp();
		work(i);
	}

	if (ans == INF)
		cout << "Impossible" << ENDL;
	else
		cout << ans << ENDL;
}

int main()
{
	mp['w'] = 'b';
	mp['b'] = 'w';
	ios::sync_with_stdio(0);
	cin.tie(0);

	solve();

	return 0;
}