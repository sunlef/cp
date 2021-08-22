/***

    Filename:   C.cpp
    Author:     CleanBlue
    Time:       2021-06-09 20:29:59 utc+8
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

LL n;
LL a[SIZE];

void solve()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	if (n == 1) {
		cout << 1 << " " << 1 << ENDL;
		cout << 1 << ENDL;
		cout << 1 << " " << 1 << ENDL;
		cout << -1 << ENDL;
		cout << 1 << " " << 1 << ENDL;
		cout << -a[1] << ENDL;
		return;
	}

	cout << 1 << " " << n - 1 << ENDL;
	for (int i = 1; i < n; ++i) {
		cout << (LL)(n - 1) * a[i] << " \n"[i == n - 1];
		a[i] += (LL)(n - 1) * a[i];
	}

	cout << n << " " << n << ENDL;
	cout << -a[n] << ENDL;
	a[n] = 0;

	cout << 1 << " " << n << ENDL;
	for (int i = 1; i <= n; ++i)
		cout << -a[i] << " \n"[i == n];
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