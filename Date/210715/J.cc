/***

    Filename:   J.cc
    Author:     CleanBlue
    Time:       2021-07-15 15:44:51 utc+8
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
const int MAXN = 514;

int n;
char _m[SIZE][SIZE];
int m[SIZE][SIZE];
int ans[SIZE][SIZE];

void solve()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			cin >> _m[i][j];

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			m[i][j] = _m[i][j] - '0';

	for (int i = 1; i <= n; ++i)
		for (int j = i + 1; j <= n; ++j) {
			LL cnt = 0;
			for (int k = i + 1; k < j; ++k)
				cnt += m[i][k] * m[k][j];
			if ((cnt + 1) % 10 == m[i][j])
				m[i][j] = 1;
			else
				m[i][j] = 0;
		}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j)
			cout << m[i][j];
		cout << ENDL;
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