/***

    Filename:   A.cpp
    Author:     CleanBlue
    Time:       2021-06-10 22:37:40 utc+8
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
const int MAXN = 114;

int n;
int a[SIZE];
int pos1, pos2;

void solve()
{
	int minn = INF, maxx = -INF;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (a[i] > maxx) {
			maxx = a[i];
			pos2 = i;
		}
		if (a[i] < minn) {
			minn = a[i];
			pos1 = i;
		}
	}
	if (pos1 > pos2)
		swap(pos1, pos2);
	int ans1 = pos2, ans2 = n - pos1 + 1;
	int ans3 = pos1 + n - pos2 + 1;
	cout << min({ans1, ans2, ans3}) << ENDL;
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