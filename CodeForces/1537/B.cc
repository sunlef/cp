/***

    Filename:   B.cc
    Author:     CleanBlue
    Time:       2021-07-12 10:47:40 utc+8
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
const int INF = 0x7fffffff;
const int MAXN = 114514;

LL n, m, i, j;

void solve()
{
	LL ans = -INF;
	PLL ansa, ansb;
	cin >> n >> m >> i >> j;
	for (int ii = 1; ii <= 4; ++ii) {
		PLL a, b;
		if (ii == 1)
			a = {1, 1};
		else if (ii == 2)
			a = {n, 1};
		else if (ii == 3)
			a = {1, m};
		else
			a = {n, m};
		for (int jj = 1; jj <= 4; ++jj) {
			if (jj == 1)
				b = {1, 1};
			else if (jj == 2)
				b = {n, 1};
			else if (jj == 3)
				b = {1, m};
			else
				b = {n, m};
			LL tmp = 0;
			tmp += abs(i - a.first) + abs(j - a.second);
			tmp += abs(a.first - b.first) + abs(a.second - b.second);
			tmp += abs(i - b.first) + abs(j - b.first);
			if (tmp > ans) {
				ans = tmp;
				ansa = a;
				ansb = b;
			}
		}
	}
	cout << ansa.first << " " << ansa.second << " " << ansb.first << " " << ansb.second << ENDL;
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