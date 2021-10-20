#include<iostream>
#include<cstdio>
#include<cmath>
#define SYNC ios::sync_with_stdio(0), cin.tie(0)
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
using namespace std;
const int MAXN = 11451;
int N, F;
int pie[MAXN];
double V(int r){	//体积
	return PI * r * r;
}
bool check(double x){
	int cnt = 0;
	for(int i = 1; i <= N; ++i)
		cnt += V(pie[i]) / x;
	return cnt >= F+1;
}
int main(){
	int T;
	cin >> T;
	while(T--){
		cin >> N >> F;
		for(int i = 1; i <= N; ++i)
			cin >> pie[i];
		double l = 0, r = INF;
		for(int i = 1; i <= 60; ++i){	//二分答案，体积
			double m = (l+r) / 2;
			if(check(m))
				l = m;
			else
				r = m;
		}
		printf("%.4f\n", l);
	}
}
