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
#define INF 1e19
#define EPS 1e-6
#define endl '\n'
using namespace std;
const int MAXN = 11451;
long long n;
long long gcd(long long a, long long b){
	return b == 0 ? a : gcd(b, a%b);
}
long long gcdSUM(long long a){
	long long _a = a;
	long long tmp = 0;
	while(_a){
		tmp += _a%10;
		_a /= 10;
	}
	return gcd(a, tmp);
}
void solve(){
	cin >> n;
	while(gcdSUM(n) == 1)
		++n;
	cout << n << endl;
}
int main(){
	SYNC;
	int t;
	cin >> t;
	while(t--)
		solve();
}
