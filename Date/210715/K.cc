/***

    Filename:   K.cc
    Author:     CleanBlue
    Time:       2021-07-15 16:51:23 utc+8
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
const int MAXN = 1145;

int n, m;
char mm[SIZE][SIZE];
int Ai, Aj;

void solve()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			cin >> mm[i][j];
			if (mm[i][j] == 'A')
				Ai = i, Aj = j;
		}

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (mm[i][j] == '.')
				mm[i][j] = 'a';

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j)
			cout << mm[i][j];
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