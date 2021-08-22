/***

    Filename:   yls.cc
    Author:     CleanBlue
    Time:       2021-07-16 16:26:38 utc+8
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
//const int INF = 0x3f3f3f3f;
const int MAXN = 31;

int k;
LL DP[SIZE][SIZE][SIZE][SIZE][SIZE];
int a, b, c, d, e;

void solve()
{
	a = b = c = d = e = 0;
	for (int i = 1; i <= k; ++i) {
		switch (i) {
			case 1:
				cin >> a;
				break;
			case 2:
				cin >> b;
				break;
			case 3:
				cin >> c;
				break;
			case 4:
				cin >> d;
				break;
			case 5:
				cin >> e;
		}
	}

	memset(DP, 0, sizeof DP);
	DP[0][0][0][0][0] = 1;

	for (int i = 0; i <= a; ++i)
		for (int j = 0; j <= min(i, b); ++j)
			for (int kk = 0; kk <= min(j, c); ++kk)
				for (int l = 0; l <= min(kk, d); ++l)
					for (int m = 0; m <= min(l, e); ++m) {
						LL& v = DP[i][j][kk][l][m];
						if (i && i - 1 >= j)
							v += DP[i - 1][j][kk][l][m];
						if (j && j - 1 >= kk)
							v += DP[i][j - 1][kk][l][m];
						if (kk && kk - 1 >= l)
							v += DP[i][j][kk - 1][l][m];
						if (l && l - 1 >= m)
							v += DP[i][j][kk][l - 1][m];
						if (m)
							v += DP[i][j][kk][l][m - 1];
					}

	cout << DP[a][b][c][d][e] << ENDL;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> k, k)
		solve();

	return 0;
}