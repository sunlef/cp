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
int dir = 0;//0:r
			//1:d
			//2:l
			//3:u
int n;
int m[20][20];
void solve(){
	cin >> n;
	int nowi = 1;
	int nowj = 1;
	for(int step = 1; step <= n*n; ++step){
		m[nowi][nowj] = step;
		if(dir == 0){
			++nowj;
			if(nowj > n){
				nowj--;
				dir = 1;
				++nowi;
			}
		}
		else if(dir == 1){
			++nowi;
			if(nowi > n){
				nowi--;
				dir = 2;
				--nowj;
			}
		}
		else if(dir == 2){
			--nowj;
			if(nowj == 0){
				++nowj;
				dir = 3;
				--nowi;
			}
		}
		else{
			--nowi;
			if(nowi == 0){
				++nowi;
				dir = 0;
				++nowj;
			}
		}
	}
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j)
			cout << m[i][j] << " ";
		cout << endl;
	}
}
int main(){
	SYNC;
	solve();
}
