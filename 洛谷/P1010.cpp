/***

    Filename:   P1010.cpp
    Author:     CleanBlue
    Time:       2021-06-09 15:14:31 utc+8
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
string ans;

void dfs(int x)
{
	if (x == 1) {
		if (ans.size() && ans[ans.size() - 1] != '(')
			ans = ans + '+';
		ans = ans + "2(0)";
		return;
	}

	int p = 0;
	int tmp = 1;

	while (tmp * 2 <= x) {
		tmp *= 2;
		++p;
	}

	if (p == 0) {
		if (ans.size() && ans[ans.size() - 1] != '(')
			ans = ans + '+';
		ans = ans + "2(0)";
	}
	else if (p == 1) {
		if (ans.size() && ans[ans.size() - 1] != '(')
			ans = ans + '+';
		ans = ans + '2';
	}
	else {
		if (ans.size() && ans[ans.size() - 1] != '(')
			ans = ans + '+';
		ans = ans + "2(";
		dfs(p);
		ans = ans + ")";
	}

	if (x - tmp)
		dfs(x - tmp);
}

void solve()
{
	ans = "";
	cin >> n;
	dfs(n);
	cout << ans << endl;
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