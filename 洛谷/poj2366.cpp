//用stl
#define SYNC ios::sync_with_stdio(0),cin.tie(0)
const int MAXN = 114514;
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int A, B;
int a[MAXN], b[MAXN];
int main(){
	SYNC;
	cin >> A;
	for(int i = 1; i <= A; ++i)
		cin >> a[i];
	cin >> B;
	for(int i = 1; i <= B; ++i)
		cin >> b[i];
	for(int i = 1; i <= B; ++i)	
		if(binary_search(a+1, a+A+1, 10000 - b[i])){
			puts("YES");
			return 0;
		}
	puts("NO");
}
