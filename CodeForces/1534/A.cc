/***

    Filename:   A.cc
    Author:     CleanBlue
    Time:       2021-06-13 23:37:15 utc+8
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
const int MAXN = 54;

int n, m;
char f[SIZE][SIZE];
char t[SIZE][SIZE];
vector<PII> v;

bool check()
{
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (i > 1 && f[i - 1][j] == 'W' && f[i][j] == 'W')
				return false;
			if (i > 1 && f[i - 1][j] == 'R' && f[i][j] == 'R')
				return false;
			if (j > 1 && f[i][j - 1] == 'W' && f[i][j] == 'W')
				return false;
			if (i > 1 && f[i][j - 1] == 'R' && f[i][j] == 'R')
				return false;
		}
	}
	return true;
}

bool check2()
{
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (i > 1 && t[i - 1][j] == 'W' && t[i][j] == 'W')
				return false;
			if (i > 1 && t[i - 1][j] == 'R' && t[i][j] == 'R')
				return false;
			if (j > 1 && t[i][j - 1] == 'W' && t[i][j] == 'W')
				return false;
			if (i > 1 && t[i][j - 1] == 'R' && t[i][j] == 'R')
				return false;
		}
	}
	return true;
}

void solve()
{
	v.clear();
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			cin >> f[i][j];
			if (f[i][j] == '.')
				v.push_back({i, j});
		}
	if (v.size() == 0) {
		if (check()) {
			cout << "YES" << ENDL;
			for (int i = 1; i <= n; ++i) {
				for (int j = 1; j <= m; ++j)
					cout << f[i][j];
				cout << ENDL;
			}
			return;
		}
		else {
			cout << "NO" << ENDL;
			return;
		}
	}
	auto p = *v.begin();
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			t[i][j] = f[i][j];
	t[p.first][p.second] = 'W';
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			if (t[i][j] != '.')
				continue;
			if (j > 1 && t[i][j - 1] == 'W')
				t[i][j] = 'R';
			if (j > 1 && t[i][j - 1] == 'R')
				t[i][j] = 'W';
			if (j == 1 && t[i - 1][j] == 'W')
				t[i][j] = 'R';
			if (j == 1 && t[i - 1][j] == 'R')
				t[i][j] = 'W';
		}
	if (check2()) {
		cout << "YES" << ENDL;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j)
				cout << t[i][j];
			cout << ENDL;
		}
		return;
	}
	p = *v.begin();
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			t[i][j] = f[i][j];
	t[p.first][p.second] = 'R';
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			if (t[i][j] != '.')
				continue;
			if (j > 1 && t[i][j - 1] == 'W')
				t[i][j] = 'R';
			if (j > 1 && t[i][j - 1] == 'R')
				t[i][j] = 'W';
			if (j == 1 && t[i - 1][j] == 'W')
				t[i][j] = 'R';
			if (j == 1 && t[i - 1][j] == 'R')
				t[i][j] = 'W';
		}
	if (check2()) {
		cout << "YES" << ENDL;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j)
				cout << t[i][j];
			cout << ENDL;
		}
		return;
	}
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