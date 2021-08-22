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
int n, k;
priority_queue<int, vector<int>, greater<int> > q;
string s;
void solve(){
	cin >> n >> k;
	for(int i = 1; i <= n; ++i){
		cin >> s;
		int tmp = 0;
		int pos = 0;
		for(int j = s.size(); j >= 0; --j){
			if(s[j] == '/'){
				pos = j;
				break;
			}
		}
		++pos;
		for(int j = pos; j < s.size(); ++j)
			tmp = 10*tmp+s[j]-'0';
		q.push(tmp);
	}
	for(int i = 1; i <= k; ++i){
		cout << q.top() << " ";
		q.pop();
	}
	cout << endl;
}
int main(){
	SYNC;
	int t;
	cin >> t;
	while(t--){
		solve();
		while(!q.empty())
			q.pop();
	}
}
