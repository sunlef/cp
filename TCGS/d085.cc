#include<cstdio>
#include<algorithm>
int main(){
	int n;
	scanf("%d", &n);
	double sum = 0;
	int maxx = -0x3f3f3f3f;
	int minn = 0x3f3f3f3f;
	for(int i = 1; i <= n; ++i){
		int x;
		scanf("%d", &x);
		maxx = std::max(x, maxx);
		minn = std::min(x, minn);
		sum += x;
	}
	printf("%.2lf\n%d\n%d\n", sum/n, maxx, minn);
}
