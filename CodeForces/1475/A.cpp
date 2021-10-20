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
void solve(){
	long long n;
	cin >> n;
	if(n % 2 == 1){
		cout << "YES" << endl;
		return;
	}
	for(long long i = 3; i <= sqrt(n); i += 2){
		if(n % i == 0){
			cout << "YES" << endl;
			return;	
		}
	}
	cout << "NO" << endl;
}
int main(){
	SYNC;
	int t;
	cin >> t;
	while(t--)
		solve();
}
