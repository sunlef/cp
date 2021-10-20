/***

    Filename:   C.cpp
    Author:     CleanBlue
    Time:       2021-06-10 22:50:21 utc+8
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
const int MAXN = 214514;

int n;
int a[SIZE];
int l, r;

void solve()
{
	cin >> n >> l >> r;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	LL ans = 0;
	for (int i = 1; i < n; ++i) {
		int pos1 = lower_bound(a + i + 1, a + n + 1, l - a[i]) - a;
		if (pos1 == n + 1)
			continue;
		int pos2 = upper_bound(a + i + 1, a + n + 1, r - a[i]) - a;
		ans += pos2 - pos1;
		//cout << pos1 << " " << pos2 << ENDL;
	}
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