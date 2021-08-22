/***

    Filename:   B.cpp
    Author:     CleanBlue
    Time:       2021-06-09 19:48:36 utc+8
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

LL n;
LL a[SIZE];
LL ans;

void solve()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	sort(a, a + n);
	ans = 1e18;

	for (int d = 1; d <= 1e6; ++d) {
		LL tmp = 0;
		LL now = 1;
		for (int i = 0; i < n; ++i) {
			tmp += abs(a[i] - now);
			now *= d;
			if (now > 1e17) {
				cout << ans << ENDL;
				return;
			}
		}
		ans = min(ans, tmp);
	}

	cout << ans << ENDL;
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