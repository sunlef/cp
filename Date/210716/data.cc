/***

    Filename:   data.cc
    Author:     CleanBlue
    Time:       2021-07-16 17:23:00 utc+8
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
#include <ctime>

#define ENDL '\n'
#define SIZE MAXN
#define PUB  push_back
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
const int MAXN = 114514;

char m[5][5];
LL randint(LL l, LL r)
{
	LL k = l;
	r++;
	k += (1.0 * rand() / RAND_MAX) * (r - l);
	return k;
}
/*
//随机整数：randint(l,r) : [l,r]之间的数.
//      //int n = randint(1, 10);
//随机小写字母：(char) randint ('a','z').
//    大写   ：(char) randint ('A','Z').
//PS：main函数中加这句"srand(time(0)// time(0))"
*/

void solve()
{
	for (int i = 1; i <= 4; ++i)
		for (int j = 1; j <= 4; ++j) {
			if (randint(1, 10000000) & 1)
				m[i][j] = 'w';
			else
				m[i][j] = 'b';
		}
	for (int i = 1; i <= 4; ++i) {
		for (int j = 1; j <= 4; ++j)
			cout << m[i][j];
		cout << ENDL;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	srand(time(0));
	int T = 1;
	//cin >> T;
	while (T--)
		solve();

	return 0;
}