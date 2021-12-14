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
double a, b, c, d;
void solve(){
	cin >> a >> b >> c >> d;
	for(double i = -100.00; i <= 100.00; i += 0.001){
		double l = i, r = i+0.001;
		if((a*l*l*l+b*l*l+c*l+d)*(a*r*r*r+b*r*r+c*r+d) < 0){
			printf("%.2f ", i);
		}
	}
	cout << endl;

}
int main(){
	SYNC;
	solve();
}
