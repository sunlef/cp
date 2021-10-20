/***

    Filename:   A.cpp
    Author:     CleanBlue
    Time:       2021-06-06 20:00:06 utc+8
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

int a, b;
void solve()
{
	cin >> a >> b;
	if (a == b) {
		cout << a << endl;
		return;
	}
	if ((a == 0 && b == 1) || (a == 1 && b == 0)) {
		cout << 2 << ENDL;
		return;
	}
	if ((a == 0 && b == 2) || (a == 2 && b == 0)) {
		cout << 1 << ENDL;
		return;
	}
	if ((a == 1 && b == 2) || (a == 2 && b == 1)) {
		cout << 0 << endl;
		return;
	}
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