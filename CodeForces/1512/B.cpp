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
const int MAXN = 514;
int n;
char m[MAXN][MAXN];
struct Node{
	int a, b;
}A[3];
void solve(){
	cin >> n;
	int cnt = 0;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j){
			cin >> m[i][j];
			if(m[i][j] == '*'){
				A[++cnt].a = i;
				A[cnt].b = j;
			}
		}
	if(A[1].a == A[2].a){
		if(A[1].a == 1){
			for(int i = 1; i <= n; ++i){
				for(int j = 1; j <= n; ++j){
					if((j == A[1].b || j == A[2].b) && i == n)
						cout << "*";
					else
						cout << m[i][j];
				}
				cout << endl;
			}
		}
		else{
			for(int i = 1; i <= n; ++i){
				for(int j = 1; j <= n; ++j){
					if((j == A[1].b || j == A[2].b) && i == 1)
						cout << "*";
					else
						cout << m[i][j];
				}
				cout << endl;
			}
		}
		return;
	}
	if(A[1].b == A[2].b){
		if(A[1].b == 1){
			for(int i = 1; i <= n; ++i){
				for(int j = 1; j <= n; ++j){
					if((i == A[1].a || i == A[2].a) && j == n)
						cout << "*";
					else
						cout << m[i][j];
				}
				cout << endl;
			}
		}
		else{
			for(int i = 1; i <= n; ++i){
				for(int j = 1; j <= n; ++j){
					if((i == A[1].a || i == A[2].a) && j == 1)
						cout << "*";
					else
						cout << m[i][j];
				}
				cout << endl;
			}
		}
		return;
	}
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			if((i == A[1].a || i == A[2].a) && (j == A[1].b || j == A[2].b))
				cout << '*';
			else
				cout << '.';
		}
		cout << endl;
	}

}
int main(){
	SYNC;
	int T;
	cin >> T;
	while(T--){
		solve();
	}
}
