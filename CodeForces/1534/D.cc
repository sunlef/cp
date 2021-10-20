/***

    Filename:   D.cc
    Author:     CleanBlue
    Time:       2021-06-14 01:44:41 utc+8
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
const int MAXN = 2514;

int n;
set<PII> ans;
int d;

void solve()
{
	int now = 1;
	cin >> n;

	while (ans.size() < n - 1) {
		cout << '?' << " " << now << endl;
		for (int i = 1; i <= n; ++i) {
			cin >> d;
			if (d == 2)
				now = i;
			if (d == 1) {
				ans.insert({min(now, i), max(now, i)});
			}
		}
		DIV;
		for (auto i : ans) {
			cout << i.first << " " << i.second << endl;
		}
		DIV;
	}

	for (auto i : ans) {
		cout << i.first << " " << i.second << endl;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	solve();

	return 0;
}