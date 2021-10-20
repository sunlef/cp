/***

    Filename:   E.cc
    Author:     CleanBlue
    Time:       2021-07-14 14:01:30 utc+8
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
const int INF = 0x3f3f3f3f;
const int MAXN = 114;

short N, K;
vector<short> G[SIZE];

LL DP[SIZE][SIZE][2];

void DFS(short u, short fa)
{
	for (int i = 0; i < G[u].size(); ++i) {
		int v = G[u][i];
		if (v == fa)
			continue;

		DFS(v, u);

		for (int j = K; j >= 1; --j) {
			DP[u][j][false] = max(DP[u][j][false], DP[u][j - 1][true] + DP[v][0][false]);
			for (int t = 2; t <= j; ++t) {
				DP[u][j][true] = max(DP[u][j][true], DP[u][j - t][true] + DP[v][t - 2][true]);
				DP[u][j][false] = max(
				    DP[u][j][false],
				    max(DP[u][j - t][true] + DP[v][t - 1][false],
				        DP[u][j - t][false] + DP[v][t - 2][true]));
			}
		}
	}
}

void solve()
{
	memset(DP, 0, sizeof DP);
	for (int i = 1; i <= N; ++i)
		G[i].clear();

	for (int i = 1; i <= N; ++i) {
		short w;
		cin >> w;
		for (int j = 0; j <= K; ++j)
			DP[i][j][false] = DP[i][j][true] = w;
	}

	for (int i = 1; i < N; ++i) {
		short u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	DFS(1, -1);

	cout << max(DP[1][K][false], DP[1][K][true]) << ENDL;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> N >> K)
		solve();

	return 0;
}