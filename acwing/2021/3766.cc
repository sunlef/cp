/***

    Filename:   3766.cc
    Author:     CleanBlue
    Time:       2021-07-12 20:00:52 utc+8
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
const int MAXN = 114514;

int n, m;

void solve()
{
	cin >> n >> m;
	int sum = 0;
	int cnt = 0;
	int minn = INF;
	for (int i = 1; i <= n * m; ++i) {
		int tmp;
		cin >> tmp;
		if (tmp < 0) {
			++cnt;
			tmp *= -1;
		}
		sum += tmp;
		minn = min(minn, tmp);
	}

	if (cnt & 1)
		cout << sum - 2 * minn << ENDL;
	else
		cout << sum << ENDL;
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