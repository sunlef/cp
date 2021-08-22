/***

    Filename:   d.cc
    Author:     CleanBlue
    Time:       2021-06-12 06:21:24 utc+8
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

int calc(int x)
{
	int res = 0;
	for (int i = 2; i * i <= x; ++i) {
		while (x % i == 0) {
			++res;
			x /= i;
		}
	}

	if (x > 1)
		++res;

	return res;
}

void solve()
{
	int a, b, k;
	cin >> a >> b >> k;

	if (a > b)
		swap(a, b);

	int U = calc(a) + calc(b);
	int D = 2;

	if (b % a == 0 && a != b)
		D = 1;

	if (D <= k && k <= U)
		cout << "YES" << ENDL;
	else
		cout << "NO" << ENDL;
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