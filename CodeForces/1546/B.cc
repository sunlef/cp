/***

    Filename:   B.cc
    Author:     CleanBlue
    Time:       2021-07-12 13:30:32 utc+8
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

int n, m;
string s;
int cnt[SIZE][26];

void solve()
{
	memset(cnt, 0, sizeof cnt);
	cin >> n >> m;

	for (int i = 1; i <= n; ++i) {
		cin >> s;
		for (int j = 0; j < m; ++j)
			cnt[j][s[j] - 'a']++;
	}

	for (int i = 1; i < n; ++i) {
		cin >> s;
		for (int j = 0; j < m; ++j)
			cnt[j][s[j] - 'a']--;
	}

	for (int i = 0; i < m; ++i)
		for (int j = 0; j < 26; ++j)
			if (cnt[i][j])
				cout << (char)(j + 'a');
	cout << endl;
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