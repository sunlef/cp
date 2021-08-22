//记得乘1ll
//别让小数变成珂学计数
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
string m[10][10];
int n;
string s;
void solve(){
	cin >> n;
	cin >> s;
	for(int i = 1; i <= 5; ++i){
		for(int j = 0; j < s.size(); ++j){
			cout << m[s[j]-'0'][i];
			if(j != s.size() - 1)
				cout << '.';
		}
		cout << endl;
	}
}
int main(){
	SYNC;
	m[0][1] = m[0][5] = "XXX";
	m[0][2] = m[0][3] = m[0][4] = "X.X";
	for(int i = 1; i <= 5; ++i)
		m[1][i] = "..X";
	m[2][1] = m[2][3] = m[2][5] = "XXX";
	m[2][2] = "..X";
	m[2][4] = "X..";
	m[3][1] = m[3][3] = m[3][5] = "XXX";
	m[3][2] = m[3][4] = "..X";
	m[4][3] = m[3][1];
	m[4][1] = m[4][2] = "X.X";
	m[4][4] = m[4][5] = "..X";
	m[5][1] = m[5][3] = m[5][5] = m[3][1];
	m[5][2] = m[2][4];
	m[5][4] = m[2][2];
	m[6][1] = m[6][3] = m[6][5] = "XXX";
	m[6][2] = "X..";
	m[6][4] = "X.X";
	m[7][1] = "XXX";
	for(int i = 2; i <= 5; ++i)
		m[7][i] = "..X";
	m[8][1] = m[8][3] = m[8][5] = "XXX";
	m[8][2] = m[8][4] = "X.X";
	m[9][1] = m[9][3] = m[9][5] = "XXX";
	m[9][2] = "X.X";
	m[9][2] = "X.X";
	m[9][4] = "..X";
	solve();
}
