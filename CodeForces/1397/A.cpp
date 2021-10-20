/***

    Filename:   A.cpp
    Author:     CleanBlue
    Time:       2021-06-09 19:35:05 utc+8
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
const int MAXN = 1145;

int n;
int cnt[30];

void solve()
{
	for (int i = 0; i < 26; ++i)
		cnt[i] = 0;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); ++j)
			cnt[s[j] - 'a']++;
	}
	for (int i = 0; i < 26; ++i) {
		if (cnt[i] == 0)
			continue;
		if (cnt[i] % n != 0) {
			cout << "NO" << ENDL;
			return;
		}
	}
	cout << "YES" << ENDL;
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