/***

    Filename:   3761.cc
    Author:     CleanBlue
    Time:       2021-07-12 15:24:35 utc+8
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
const int MAXN = 214514;

int n;
int a[SIZE];

map<int, int> mp;

void solve()
{
	mp.clear();
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (mp[a[i]])
			mp[a[i]] = -1;
		else
			mp[a[i]] = i;
	}

	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i)
		if (mp[a[i]] && mp[a[i]] != -1) {
			cout << mp[a[i]] << ENDL;
			return;
		}

	cout << -1 << ENDL;
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