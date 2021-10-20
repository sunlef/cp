/***

    Filename:   cf1307a.cc
    Author:     CleanBlue
    Time:       2021-07-16 19:53:39 utc+8
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
#define PUB  push_back
#define DIV  cout << "\n==============================\n"

using namespace std;
typedef long long LoveLive;
typedef long double LD;
typedef unsigned long long ULL;
typedef LoveLive LL;
typedef pair<int, int> PII;
typedef pair<LoveLive, int> PLI;
typedef pair<LoveLive, LoveLive> PLL;
typedef vector<int> VI;
typedef vector<LoveLive> VLL;

//const double PI = acos(-1.0);
//const double EPS = 1e-6;
//const int INF = 0x3f3f3f3f;
const int MAXN = 114514;

int n, d;
int a[SIZE];

void solve()
{
	cin >> n >> d;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	for (int i = 2; i <= n && d; ++i) {
		if (d < i - 1)
			break;
		while (d >= i - 1 && a[i])
			++a[1], --a[i], d -= i - 1;
	}

	cout << a[1] << ENDL;
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