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
const int MAXN = 214514;
int A, B, K;
struct Node{
	int a, b;
}p[MAXN];
void solve(){
	cin >> A >> B >> K;
	for(int i = 1; i <= K; ++i)
		cin >> p[i].a >> p[i].b;
}
int main(){
	SYNC;
	int t;
	cin >> t;
	while(t--)
		solve();
}
