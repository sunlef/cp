/***

    Filename:   A.cc
    Author:     CleanBlue
    Time:       2021-07-14 15:44:15 utc+8
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

LL n, x, t;

void solve()
{
	cin >> n >> x >> t;

	//if (x > t)
	//	cout << 0 << ENDL;
	//else if (x == t)
	//	cout << n << ENDL;
	//else {
	LL ans = t / x;
	if (ans < n)
		ans = (n - ans) * ans + ans * (ans - 1) / 2;
	else
		ans = (n - 1) * n / 2;
	cout << ans << ENDL;
	//}
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