/***

    Filename:   F.cpp
    Author:     CleanBlue
    Time:       2021-06-11 00:11:56 utc+8
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

LL calc(int x)
{
	int _x = x;
	int len = 0;
	while (_x)
		++len, _x /= 10;
	LL res = 0;
	for (int i = 0; i <= len; ++i) {
		res += x;
		x /= 10;
	}
	return res;
}

int n;
int l, r;

void solve()
{
	cin >> l >> r;
	cout << calc(r) - calc(l) << ENDL;
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