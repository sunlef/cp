/***

    Filename:   A.cpp
    Author:     CleanBlue
    Time:       2021-06-01 19:30:57 utc+8
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
typedef pair<LL, int> PLI;
typedef pair<LL, LL> PLL;

//const double PI = acos(-1.0);
//const double EPS = 1e-6;
//const int INF = 0x3f3f3f3f;
const int MAXN = 114514;
const int MOD = 1e9 + 7;

void solve()
{
	string s;
	cin >> s;
	LL cntn = 0, cntya = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == 'n')
			++cntn;
		else if (s[i] == 'y' && i < s.size() - 1 && s[i + 1] == 'a')
			++cntya;
	}
	LL ans = s.size();
	int k;
	cin >> k;
	while (k--) {
		char ch;
		cin >> ch;
		if (ch == 'N') {
			ans = (ans + cntn * 2) % MOD;
			cntya += cntn;
		}
		else {
			ans = (ans - cntya) % MOD;
			cntn += cntya;
			cntya = 0;
		}
	}
	cout << cntn << " " << cntya << ENDL;
	if (ans < 0)
		cout << ans + MOD << ENDL;
	else
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