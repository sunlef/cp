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
int n;
void solve(){
	long long maxx = -INF;
	long long minn = INF;
	long long sum = 0;
	cin >> n;
	int _n = n;
	long long tmp;
	while(_n--){
		cin >> tmp;
		sum += tmp;
		maxx = max(tmp, maxx);
		minn = min(tmp, minn);
	}
	double ans = sum*1.0 / n;
	cout << maxx << endl << minn << endl;
	printf("%.2f\n", ans);
}
int main(){
	//SYNC;
	solve();
}
