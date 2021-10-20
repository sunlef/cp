#define SYNC ios::sync_with_stdio(0),cin.tie(0)
#define INF 0x3f3f3f3f
#include<iostream>
using namespace std;
const int MAXN = 11451;
int N, K;
double a[MAXN];
bool check(double x){
	int cnt = 0;
	for(int i = 1; i <= N; ++i)
		cnt += a[i] / x;
	return cnt >= K;
}
int main(){
	SYNC;
	cin >> N >> K;
	for(int i = 1; i <= N; ++i)
		cin >> a[i];
	double l = 0, r = INF;
	for(int i = 1; i <= 60; ++i){
		double m = (l+r) / 2;
		if(check(m))
			l = m;
		else
			r = m;
	}
	printf("%.2f\n", (double)((int)(100*l)) / 100);
}
