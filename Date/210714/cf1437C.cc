/***

    Filename:   cf1437C.cc
    Author:     CleanBlue
    Time:       2021-07-14 14:47:24 utc+8
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
const int MAXN = 214;

short n;
short t[SIZE];
int DP[SIZE << 1][SIZE];

void solve()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> t[i];
	sort(t + 1, t + n + 1);

	memset(DP, 0x3f, sizeof DP);

	for (int i = 0; i <= 400; ++i)
		DP[i][0] = 0;

	for (short i = 1; i <= 400; ++i)
		for (short j = 1; j <= n; ++j)
			DP[i][j] = min(DP[i - 1][j], DP[i - 1][j - 1] + abs(i - t[j]));

	cout << DP[400][n] << ENDL;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T = 1;
	cin >> T;
	while (T--)
		solve();

	return 0;
}