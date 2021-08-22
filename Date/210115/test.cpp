#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=100005,INF=0x3f3f3f3f;
int n,a[maxn];
bool check(int x){
	int cnt=0;
	for(int i=1,j=1;i<=n;++i){
		while(a[j]<=a[i]+x&&j<=n) ++j;
		--j;
		cnt+=j-i;
	}
	if(!(((n*(n-1))>>1)&1)) return cnt < (n*(n-1))>>2;
	else return cnt <= (n*(n-1))>>2;
}
int main(){
	while(scanf("%d",&n)!=EOF){
		for(int i=1;i<=n;++i) scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		int l=0,r=INF;
		while(l<r){
			int mid=l+r>>1;
			if(check(mid)) l=mid+1;
			else r=mid;
		}
		printf("%d\n",l);
	}
	return 0;
} 
