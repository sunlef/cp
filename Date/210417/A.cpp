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
string n1, n2, n3;
int a1, a2, a3;
string chord[] = {"", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
map<string, int> mp;
void solve(){
	cin >> n1 >> n2 >> n3;
	a1 = mp[n1];
	a2 = mp[n2];
	a3 = mp[n3];
	int now = a1;
	for(int i = 1; i <= 4; ++i){
		now++;
		if(now == 13)
			now = 1;
	}
	if(now == a2){
		for(int i = 1; i <= 3; ++i){
		now++;
		if(now == 13)
			now = 1;
		}
		if(now == a3){
			cout << "Major triad" << endl;
			return;
		}
	}
	now = a1;
	for(int i = 1; i <= 3; ++i){
		now++;
		if(now == 13)
			now = 1;
	}
	if(now == a2){
		for(int i = 1; i <= 4; ++i){
		now++;
		if(now == 13)
			now = 1;
		}
		if(now == a3){
			cout << "Minor triad" << endl;
			return;
		}
	}
	cout << "Dissonance" << endl;
}
int main(){
	SYNC;
	for(int i = 1; i <= 12; ++i)
		mp[chord[i]] = i;
	int t;
	cin >> t;
	while(t--)
		solve();
}
