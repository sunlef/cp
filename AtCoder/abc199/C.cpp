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
const int MAXN = 414514;
int N;
int Q;
string s;
int T, A, B;
bool fliped;
int pos[MAXN];
inline int calc(int x){
	if(!fliped)
		return x;
	if(x < N)
		return x+N;
	return x-N;
}
void solve(){
	cin >> N;
	cin >> s;
	cin >> Q;
	for(int i = 0; i < 2*N; ++i)
		pos[i] = i;
	while(Q--){
		cin >> T >> A >> B;
		if(T == 1)
			swap(pos[calc(A-1)], pos[calc(B-1)]);
		else
			fliped = !fliped;
	}
	for(int i = 0; i < 2*N; ++i)
		cout << s[pos[calc(i)]];
	cout << endl;
}
int main(){
	SYNC;
	solve();
}
