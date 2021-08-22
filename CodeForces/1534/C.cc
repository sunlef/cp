/***

        Filename:   C.cc
        Author:     CleanBlue
        Time:       2021-06-14 00:32:04 utc+8
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
const int MOD = 1e9 + 7;

int n;
int a[SIZE];
int b[SIZE];
int posa[SIZE], posb[SIZE];
bool flag[SIZE];
int ans;

void solve()
{
	cin >> n;
	ans = 1;

	for (int i = 1; i <= n; ++i)
		flag[i] = false;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		posa[a[i]] = i;
	}
	for (int i = 1; i <= n; ++i) {
		cin >> b[i];
		posb[b[i]] = i;
	}

	for (int i = 1; i <= n; ++i) {
		if (flag[i])
			continue;
		flag[i] = true;
		int D = b[i];
		int pos = posa[D];
		while (pos != i) {
			flag[pos] = true;
			D = b[pos];
			pos = posa[D];
		}
		ans = (ans * 2) % MOD;
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