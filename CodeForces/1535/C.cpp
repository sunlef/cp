/***

    Filename:   C.cpp
    Author:     CleanBlue
    Time:       2021-06-04 23:40:53 utc+8
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
const int MAXN = 204514;

string s;
int dp[SIZE][2];

bool check(int l, int r)
{
	if (s[l] == '?') {
		bool flag = true;
		bool now = true;
		for (int i = l + 1; i <= r; ++i) {
			now = !now;
			if ((now == false && s[i] == '1') || (now == true && s[i] == '0')) {
				flag = false;
				break;
			}
		}
		if (flag)
			return true;
		now = false;
		for (int i = l + 1; i <= r; ++i) {
			now = !now;
			if ((now == false && s[i] == '1') || (now == true && s[i] == '0'))
				return false;
		}
		return true;
	}
	else if (s[l] == '1') {
		bool now = true;
		for (int i = l + 1; i <= r; ++i) {
			now = !now;
			if ((now == false && s[i] == '1') || (now == true && s[i] == '0'))
				return false;
		}
		return true;
	}
	else {
		bool now = false;
		for (int i = l + 1; i <= r; ++i) {
			now = !now;
			if ((now == false && s[i] == '1') || (now == true && s[i] == '0'))
				return false;
		}
		return true;
	}
}
void solve()
{
	cin >> s;
	int n = s.size();
	s = " " + s;

	LL ans = 0;
	for (int i = 1; i <= n; ++i) {
		int j = i;
		while (j + 1 <= n && check(i, j + 1))
			++j;
		int l = j - i + 1;
		ans += (l + 1) * l / 2;
		cout << i << " " << j << ENDL;
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