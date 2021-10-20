/***

    Filename:   B.cc
    Author:     CleanBlue
    Time:       2021-07-14 16:13:05 utc+8
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

int n, q;
string s;

int cnt[26][SIZE];

LL query(int l, int r)
{
	LL res = r - l + 1;
	for (int i = 0; i < 26; ++i)
		res += i * (cnt[i][r] - cnt[i][l - 1]);
	return res;
}

void solve()
{
	cin >> n >> q;
	cin >> s;
	s = " " + s;

	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < 26; ++j)
			cnt[j][i] = cnt[j][i - 1];
		cnt[s[i] - 'a'][i]++;
	}

	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << query(l, r) << ENDL;
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