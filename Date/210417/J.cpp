#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<string>
#include<cmath>
#define SYNC ios::sync_with_stdio(0),cin.tie(0)
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define EPS 1e-6
#define endl '\n'
using namespace std;
const int MAXN = 114514;
char mp[5][5];
bool op;//false: Bob//true: Alice.
int cntN, cntO, cntX;
int calc(){
	int res = 0;
	if(mp[1][1] == mp[1][2] && mp[1][2] == mp[1][3] && mp[1][1] == 'O')
		++res;
	else if(mp[1][1] == mp[1][2] && mp[1][2] == mp[1][3] && mp[1][1] == 'X')
		--res;
	if(mp[2][1] == mp[2][2] && mp[2][2] == mp[2][3] && mp[2][1] == 'O')
		++res;
	else if(mp[2][1] == mp[2][2] && mp[2][2] == mp[2][3] && mp[2][1] == 'X')
		--res;
	if(mp[3][1] == mp[3][2] && mp[3][2] == mp[3][3] && mp[3][1] == 'O')
		++res;
	else if(mp[3][1] == mp[3][2] && mp[3][2] == mp[3][3] && mp[3][1] == 'X')
		--res;
	if(mp[1][1] == mp[2][1] && mp[2][1] == mp[3][1] && mp[3][1] == 'O')
		++res;
	else if(mp[1][1] == mp[2][1] && mp[2][1] == mp[3][1] && mp[3][1] == 'X')
		--res;
	if(mp[1][2] == mp[2][2] && mp[2][2] == mp[3][2] && mp[3][2] == 'O')
		++res;
	else if(mp[1][2] == mp[2][2] && mp[2][2] == mp[3][2] && mp[3][2] == 'X')
		--res;
	if(mp[1][3] == mp[2][3] && mp[2][3] == mp[3][3] && mp[3][3] == 'O')
		++res;
	else if(mp[1][3] == mp[2][3] && mp[2][3] == mp[3][3] && mp[3][3] == 'X')
		--res;
	if(mp[1][1] == mp[2][2] && mp[2][2] == mp[3][3] && mp[3][3] == 'O')
		++res;
	else if(mp[1][1] == mp[2][2] && mp[2][2] == mp[3][3] && mp[3][3] == 'X')
		--res;
	if(mp[1][3] == mp[2][2] && mp[2][2] == mp[3][1] && mp[2][2] == 'O')
		++res;
	else if(mp[1][3] == mp[2][2] && mp[2][2] == mp[3][1] && mp[2][2] == 'X')
		--res;
	return res;
}
int ans;
void dfs(int step, bool who){
	if(who){
		int maxx = -INF;
		int x, y;
		for(int i = 1; i <= 3; ++i)
			for(int j = 1; j <= 3; ++j){
				if(mp[i][j] == '.'){
					mp[i][j] = 'O';
					int tmp = calc();
					if(maxx < tmp){
						x = i;
						y = j;
						maxx = tmp;
					}
					mp[i][j] = '.';
				}
			}
		mp[x][y] = 'O';
		if(step < cntN)
			dfs(step+1, !who);
		else
			return;
	}
	else{
		int minx = INF;
		int x, y;
		for(int i = 1; i <= 3; ++i)
			for(int j = 1; j <= 3; ++j){
				if(mp[i][j] == '.'){
					mp[i][j] = 'X';
					int tmp = calc();
					if(minx > tmp){
						x = i;
						y = j;
						minx = tmp;
					}
					mp[i][j] = '.';
				}
			}
		mp[x][y] = 'X';
		if(step < cntN)
			dfs(step+1, !who);
		else
			return;
	}
}
void solve(){
	cin >> op;
	cntN = cntO = cntX = 0;
	for(int i = 1; i <= 3; ++i)
		for(int j = 1; j <= 3; ++j){
			cin >> mp[i][j];
			if(mp[i][j] == '.')
				++cntN;
			else if(mp[i][j] == 'O')
				++cntO;
			else
				++cntX;
		}
	if(cntN == 0){
		cout << calc() << endl;
		return;
	}
	dfs(1,op);
	cout << calc() << endl;
}
int main(){
	SYNC;
	int T;
	cin >> T;
	while(T--)
		solve();
}
