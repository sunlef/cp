/***

    Filename:   C.cc
    Author:     CleanBlue
    Time:       2021-07-12 11:07:11 utc+8
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
const int MAXN = 214514;

int n;
int h[SIZE];

void solve()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> h[i];
	sort(h + 1, h + n + 1);

	int minn = INF;
	int pos = 1;

	for (int i = 1; i < n; ++i)
		if (h[i + 1] - h[i] < minn) {
			minn = h[i + 1] - h[i];
			pos = i;
		}

	cout << h[pos] << " ";
	for (int i = pos + 2; i <= n; ++i)
		cout << h[i] << " ";
	for (int i = 1; i < pos; ++i)
		cout << h[i] << " ";
	cout << h[pos + 1] << ENDL;
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