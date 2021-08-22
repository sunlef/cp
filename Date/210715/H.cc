/***

    Filename:   H.cc
    Author:     CleanBlue
    Time:       2021-07-15 13:58:58 utc+8
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
const int INF = 0x3f3f3f3f;
const int MAXN = 214514;

int n;
LL pre[SIZE];
int m[1100000];
int q;

int calc(int t)
{
	int res = 0;
	int r = 1;
	int nowpos = 0;
	while (r <= n) {
		int pos = upper_bound(pre + r + 1, pre + n + 1, t + pre[nowpos]) - pre;
		++res;
		nowpos = pos - 1;
		r = pos;
	}
	return m[t] = res;
}

void solve()
{
	cin >> n;
	int maxx = -INF;
	for (int i = 1; i <= n; ++i) {
		int a;
		cin >> a;
		maxx = max(maxx, a);
		pre[i] = pre[i - 1] + a;
	}
	cin >> q;
	while (q--) {
		int t;
		cin >> t;
		if (m[t]) {
			cout << m[t] << ENDL;
			continue;
		}
		else if (t < maxx)
			cout << "Impossible" << ENDL;
		else if (t >= pre[n])
			cout << 1 << endl;
		else
			cout << calc(t) << ENDL;
	}
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