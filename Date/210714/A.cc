/***

    Filename:   A.cc
    Author:     CleanBlue
    Time:       2021-07-14 13:17:47 utc+8
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
const int MAXN = 25;
const int SHIFT = 7500;

LL DP[SIZE][7501 + SHIFT];
short c[SIZE], g[SIZE];
short C, G;

void solve()
{
	cin >> C >> G;
	for (int i = 1; i <= C; ++i)
		cin >> c[i];
	for (int i = 1; i <= G; ++i)
		cin >> g[i];

	DP[0][0 + SHIFT] = 1;

	for (int i = 1; i <= G; ++i)
		for (int j = -7500; j <= 7500; ++j)
			for (int k = 1; k <= C; ++k)
				DP[i][j + g[i] * c[k] + SHIFT] += DP[i - 1][j + SHIFT];

	cout << DP[G][0 + SHIFT] << ENDL;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T = 1;
	//cin >> T;
	while (T--)
		solve();

	return 0;
}