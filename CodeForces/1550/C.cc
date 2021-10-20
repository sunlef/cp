/***

    Filename:   C.cc
    Author:     CleanBlue
    Time:       2021-07-14 23:39:16 utc+8
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

int a[SIZE];
int n;

void solve()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	LL ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < 4; ++j) {  //a_i ... a_{i+j}
			if (i + j > n)
				break;
			int len = j + 1;
			if (len == 1 || len == 2)
				ans++;
			else if (len == 3) {
				if (a[i] <= a[i + 1] && a[i + 1] <= a[i + 2])
					break;
				if (a[i] >= a[i + 1] && a[i + 1] >= a[i + 2])
					break;
				++ans;
			}
			else if (len == 4) {
				if (a[i] <= a[i + 1] && a[i + 1] <= a[i + 2])
					break;
				if (a[i] <= a[i + 1] && a[i + 1] <= a[i + 3])
					break;
				if (a[i] <= a[i + 2] && a[i + 2] <= a[i + 3])
					break;
				if (a[i + 1] <= a[i + 2] && a[i + 2] <= a[i + 3])
					break;
				if (a[i] >= a[i + 1] && a[i + 1] >= a[i + 2])
					break;
				if (a[i] >= a[i + 1] && a[i + 1] >= a[i + 3])
					break;
				if (a[i] >= a[i + 2] && a[i + 2] >= a[i + 3])
					break;
				if (a[i + 1] >= a[i + 2] && a[i + 2] >= a[i + 3])
					break;
				++ans;
			}
		}
	}
	cout << ans << ENDL;
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