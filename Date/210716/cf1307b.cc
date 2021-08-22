/***

    Filename:   cf1307b.cc
    Author:     CleanBlue
    Time:       2021-07-16 20:25:32 utc+8
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
#define LB   lower_bound
#define UB   upper_bound
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

int n, x;
int a[SIZE];

void solve()
{
	cin >> n >> x;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	sort(a + 1, a + n + 1);
	int flag = 0;
	for (int i = 1; i <= n; ++i)
		if (x % a[i] == 0)
			flag = a[i];

	int ans1 = INF;
	if (flag)
		ans1 = x / flag;

	int ans2 = max(2, x / a[n] + 1);

	//cout << ans1 << " " << ans2 << ENDL;
	cout << min(ans1, ans2) << ENDL;
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