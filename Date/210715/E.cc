/***

        Filename:   E.cc
        Author:     CleanBlue
        Time:       2021-07-15 14:57:12 utc+8
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
const int MAXN = 214514;

int n, m;
vector<int> G[SIZE];
queue<int> q;
int dis[SIZE];
bool visted[SIZE];
int now[SIZE];

void bfs()
{
	while (!q.empty()) {
		int u = q.front();
		if (now[u] == m) {
			cout << "YES" << ENDL << u << ENDL;
			return;
		}
		q.pop();
		for (auto v : G[u]) {
			if (dis[v] == dis[u] + 1 || dis[v] == INF) {
				dis[v] = dis[u] + 1;
				now[v] += now[u];
				if (!visted[v])
					q.push(v);
				visted[v] = true;
			}
		}
	}
	cout << "NO" << ENDL;
}

void solve()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		dis[i] = INF;

	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	for (int i = 1; i <= m; ++i) {
		int u;
		cin >> u;
		q.push(u);
		dis[u] = 0;
		now[u] = 1;
		visted[u] = true;
	}
	bfs();
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