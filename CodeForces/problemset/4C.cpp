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
string str;
const int trieN = 30;
#define tireNode trieNode
#define tireN trieN
struct trieNode{
	trieNode **son;
	int cnt;
	tireNode(){
		cnt = 0;
		son = new trieNode*[tireN];
		for(int i = 0; i < trieN; ++i)
			son[i] = nullptr;
	}
}*root;
int query(string s){
	trieNode *p = root;
	for(auto i : s){
		int c = i - 'a';
		if(! p -> son[c])
			p -> son[c] = new trieNode;
		p = p -> son[c];
	}
	return p->cnt++;
}
void solve(){
	root = new tireNode;
	cin >> n;
	while(n--){
		cin >> str;
		int cnt = query(str);
		if(cnt == 0)
			cout << "OK" << endl;
		else
			cout << str << cnt << endl;
	}
}
int main(){
	SYNC;
	solve();
}
