/***

    Filename:   A.cpp
    Author:     CleanBlue
    Time:       2021-06-04 22:34:56 utc+8
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

PII s[5];
void solve()
{
	for (int i = 1; i <= 4; ++i) {
		cin >> s[i].first;
		s[i].second = i;
	}
	sort(s + 1, s + 5);
	if ((s[1].second == 1 && s[2].second == 2) || (s[1].second == 2 && s[2].second == 1) || (s[1].second == 3 && s[2].second == 4) || (s[1].second == 4 && s[2].second == 3))
		cout << "NO" << ENDL;
	else
		cout << "YES" << ENDL;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	while (T--)
		solve();

	return 0;
}