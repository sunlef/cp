/***

    Filename:   B.cc
    Author:     CleanBlue
    Time:       2021-06-14 00:01:22 utc+8
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
const int MAXN = 414514;

int a[SIZE];
int n;

void solve()
{
	cin >> n;
	a[n + 1] = 0;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	LoveLive ans = 0;

	for (int i = 1; i <= n; ++i)
		if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
			int maxx = max(a[i - 1], a[i + 1]);
			ans += a[i] - maxx;
			a[i] = maxx;
		}

	for (int i = 1; i < n; ++i)
		if (a[i] == a[i + 1] && a[i] > a[i - 1] && a[i + 1] > a[i + 2]) {
			int maxx = max(a[i - 1], a[i + 2]);
			ans += 2 * (a[i] - maxx);
			a[i] = a[i + 1] = maxx;
		}

	for (int i = 1; i <= n + 1; ++i)
		ans += abs(a[i] - a[i - 1]);

	cout << ans << ENDL;
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