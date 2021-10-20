/***

    Filename:   A.cpp
    Author:     CleanBlue
    Time:       2021-06-06 22:39:23 utc+8
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
const int MAXN = 2000;

int n;
int a[SIZE];
int cnt;
map<int, bool> mp;

void solve()
{
	mp.clear();
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		mp[a[i]] = true;
	}
	cnt = n;
	for (int i = 1; i <= cnt; ++i) {
		if (cnt > 300) {
			cout << "NO" << ENDL;
			return;
		}
		for (int j = 1; j <= cnt; ++j) {
			if (cnt > 300) {
				cout << "NO" << ENDL;
				return;
			}
			if (!mp[abs(a[i] - a[j])]) {
				a[++cnt] = abs(a[i] - a[j]);
				mp[abs(a[i] - a[j])] = true;
			}
		}
	}
	cout << "YES" << ENDL << cnt << ENDL;
	for (int i = 1; i <= cnt; ++i)
		cout << a[i] << " \n"[i == cnt];
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