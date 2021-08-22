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
struct Node{
	int val;
	char ch[5];
	int now_bit;
	Node nxt(Node A){
		Node tmp;
		if(A.ch[A.now_bit] == 'Z'){
			tmp.now_bit = A.now_bit+1;	
		}
	}
};
void solve(){
	
}
int main(){
	SYNC;
	solve();
}:
