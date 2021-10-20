/***

    Filename:   D.cc
    Author:     CleanBlue
    Time:       2021-07-14 19:50:57 utc+8
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

int n;
struct Node {
	LL a, b;
	bool operator<(const Node& B) const
	{
		return b < B.b;
	}
} item[SIZE];

void solve()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> item[i].a >> item[i].b;
	sort(item + 1, item + n + 1);

	LL ans = 0, now = 0;
	int l = 1, r = n;

	while (l < r) {
		if (now >= item[l].b) {
			ans += item[l].a;
			now += item[l].a;
			item[l].a = 0;
		}
		else {
			LL tmp = min(item[l].b - now, item[r].a);
			ans += 2 * tmp;
			now += tmp;
			item[r].a -= tmp;
		}
		if (item[l].a == 0)
			++l;
		if (item[r].a == 0)
			--r;
	}

	LL tmp = min(item[l].a, max(0ll, item[r].b - now));
	ans += item[r].a + tmp;

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