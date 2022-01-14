/***

    Filename:   cf1440c1.cc
    Author:     CleanBlue
    Time:       2021-07-12 15:55:52 utc+8
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
const int MAXN = 114;

int n, m;
char a[SIZE][SIZE];

void solve()
{
	int cnt = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			cin >> a[i][j];
			if (a[i][j] == '1')
				++cnt;
		}
	cout << 3 * cnt << ENDL;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			if (a[i][j] == '0')
				continue;
			if (i + 1 <= n && j + 1 <= m) {
				cout << i << " " << j << " " << i + 1 << " " << j << " " << i + 1 << " " << j + 1 << ENDL;
				cout << i << " " << j << " " << i << " " << j + 1 << " " << i + 1 << " " << j + 1 << ENDL;
				cout << i << " " << j << " " << i + 1 << " " << j << " " << i << " " << j + 1 << ENDL;
			}
			else if (i + 1 <= n && j + 1 > m) {
				cout << i << " " << j << " " << i << " " << j - 1 << " " << i + 1 << " " << j << ENDL;
				cout << i << " " << j << " " << i + 1 << " " << j << " " << i + 1 << " " << j - 1 << ENDL;
				cout << i << " " << j << " " << i << " " << j - 1 << " " << i + 1 << " " << j - 1 << ENDL;
			}
			else if (i + 1 > n && j + 1 <= m) {
				cout << i << " " << j << " " << i - 1 << " " << j << " " << i << " " << j + 1 << ENDL;
				cout << i << " " << j << " " << i - 1 << " " << j << " " << i - 1 << " " << j + 1 << ENDL;
				cout << i << " " << j << " " << i << " " << j + 1 << " " << i - 1 << " " << j + 1 << ENDL;
			}
			else {
				cout << i << " " << j << " " << i - 1 << " " << j << " " << i << " " << j - 1 << ENDL;
				cout << i << " " << j << " " << i - 1 << " " << j << " " << i - 1 << " " << j - 1 << ENDL;
				cout << i << " " << j << " " << i << " " << j - 1 << " " << i - 1 << " " << j - 1 << ENDL;
			}
		}
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