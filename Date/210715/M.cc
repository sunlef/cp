/***

    Filename:   M.cc
    Author:     CleanBlue
    Time:       2021-07-15 12:34:32 utc+8
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
#include <unordered_map>

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
const int MAXN = 2001;

int n;
int a[SIZE];

unordered_map<int, int> mp;

int READ()
{
	int res = 0;
	char CH = getchar();
	int f = 1;
	while (CH < '0' || CH > '9') {
		if (CH == '-')
			f = -1;
		CH = getchar();
	}

	while (CH >= '0' && CH <= '9') {
		res = 10 * res + CH - '0';
		CH = getchar();
	}

	return f * res;
}

void solve()
{
	mp.clear();

	n = READ();
	for (int i = 1; i <= n; ++i)
		a[i] = READ();

	int ans = 0;

	++mp[a[1]];

	for (int j = 2; j <= n; ++j) {
		for (int k = j + 1; k <= n; ++k) {
			int now = (a[j] << 1) - a[k];
			if (now) {
				ans += mp[now];
				//	cout << j << " " << k << ENDL;
			}
		}

		++mp[a[j]];
	}

	cout << ans << ENDL;
}

int main()
{
	int T = READ();
	while (T--)
		solve();

	return 0;
}