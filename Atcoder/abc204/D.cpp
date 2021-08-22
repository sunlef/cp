/***

    Filename:   D.cpp
    Author:     CleanBlue
    Time:       2021-06-06 21:37:04 utc+8
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
const int MAXN = 114;

int dp[MAXN * 1000];
int N;
int a[SIZE];

void solve()
{
}

int main()
{
	cin >> N;
	int sum = 0;
	for (int i = 1; i <= N; ++i)
		cin >> a[i];
	for (int i = 1; i <= N; ++i)
		sum += a[i];
	int V = sum >> 1;
	for (int i = 1; i <= N; ++i)
		for (int j = V; j >= a[i]; --j)
			dp[j] = max(dp[j], dp[j - a[i]] + a[i]);
	cout << max(dp[V], sum - dp[V]) << ENDL;
	return 0;
}