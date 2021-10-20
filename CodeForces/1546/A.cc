/***

    Filename:   A.cc
    Author:     CleanBlue
    Time:       2021-07-12 13:08:57 utc+8
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
int a[SIZE];
int b[SIZE];

bool check()
{
	for (int i = 1; i <= n; ++i)
		if (a[i] != b[i])
			return false;
	return true;
}

void solve()
{
	cin >> n;
	int sum1 = 0, sum2 = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		sum1 += a[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> b[i];
		sum2 += b[i];
	}

	if (sum1 != sum2) {
		cout << -1 << ENDL;
		return;
	}

	vector<PII> ans;
	while (!check()) {
		int i, j;
		bool flag = false;
		for (i = 1; i <= n; ++i) {
			for (j = 1; j <= n; ++j) {
				if (a[i] > b[i] && a[j] < b[j] && a[i] > 0) {
					a[i] -= 1;
					a[j] += 1;
					flag = true;
					ans.push_back({i, j});
					break;
				}
			}
			if (flag)
				break;
		}
	}

	cout << ans.size() << ENDL;
	for (auto i : ans)
		cout << i.first << " " << i.second << ENDL;
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