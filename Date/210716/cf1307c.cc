/***

    Filename:   cf1307c.cc
    Author:     CleanBlue
    Time:       2021-07-16 20:50:12 utc+8
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
#define PUB  push_back
#define LB   lower_bound
#define UB   upper_bound
#define DIV  cout << "\n==============================\n"

using namespace std;
typedef long long LoveLive;
typedef long double LD;
typedef unsigned long long ULL;
typedef LoveLive LL;
typedef pair<int, int> PII;
typedef pair<LoveLive, int> PLI;
typedef pair<LoveLive, LoveLive> PLL;
typedef vector<int> VI;
typedef vector<LoveLive> VLL;

//const double PI = acos(-1.0);
//const double EPS = 1e-6;
//const int INF = 0x3f3f3f3f;
const int MAXN = 55;

LL cnt[SIZE];
LL DP[SIZE][SIZE];
LL ans;
string s;

void solve()
{
	cin >> s;
	for (int i = 0; i < s.size(); ++i) {
		for (int j = 1; j <= 26; ++j) {
			DP[s[i] - 'a' + 1][j] += cnt[j];
			ans = max(ans, DP[s[i] - 'a' + 1][j]);
		}
		++cnt[s[i] - 'a' + 1];
	}

	for (int i = 1; i <= 26; ++i)
		ans = max(ans, cnt[i]);

	cout << ans << ENDL;
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