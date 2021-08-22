/***

    Filename:   B.cc
    Author:     CleanBlue
    Time:       2021-07-14 22:43:28 utc+8
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

int n, a, b;
string s;

void solve()
{
	cin >> n >> a >> b;
	cin >> s;
	s = s + " ";
	int cnt0 = 0, cnt1 = 0;
	for (auto i : s) {
		if (i == '1')
			++cnt1;
		else
			++cnt0;
	}

	LL ans1 = n * (a + b);
	LL ans2 = 0, ans3 = 0;
	int sum = 0;

	vector<int> v;
	int last = -1;
	for (int i = 0; i <= n; ++i) {
		if (s[i] == '0')
			continue;
		else {
			if (i - last - 1 > 0)
				v.push_back(i - last - 1);
			sum += i - last - 1;
			last = i;
		}
	}

	for (auto i : v)
		ans2 += a * i + b;
	if (n - sum)
		ans2 += (n - sum) * a + b;

	v.clear();
	sum = 0;
	last = -1;
	for (int i = 0; i <= n; ++i) {
		if (s[i] == '1')
			continue;
		else {
			if (i - last - 1 > 0)
				v.push_back(i - last - 1);
			sum += i - last - 1;
			last = i;
		}
	}

	for (auto i : v)
		ans3 += a * i + b;
	if (n - sum)
		ans3 += (n - sum) * a + b;

	//cout << ans1 << " " << ans2 << " " << ans3 << ENDL;
	cout << max({ans1, ans2, ans3}) << ENDL;
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