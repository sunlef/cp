/***

    Filename:   cf1321a.cc
    Author:     CleanBlue
    Time:       2021-07-14 20:02:19 utc+8
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

int n;
int a[SIZE], b[SIZE];

void solve()
{
	int cnta = 0, cntb = 0;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		cnta += a[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> b[i];
		cntb += b[i];
	}

	int cnt10 = 0;
	for (int i = 1; i <= n; ++i)
		if (a[i] == 1 && b[i] == 0)
			++cnt10;

	if (!cnt10) {
		cout << -1 << ENDL;
		return;
	}

	if (cnta > cntb) {
		cout << 1 << ENDL;
		return;
	}

	for (int i = 2; i < 114514; ++i) {
		if (cnt10 * (i - 1) + cnta - cntb > 0) {
			cout << i << ENDL;
			return;
		}
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