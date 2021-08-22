#include<iostream>
#include<algorithm>
#include<stack>
#include<cmath>
#include<vector>
#include<string>
#include<cstring>
#include<iomanip>
#include<set>
#include<map>
#include<queue>
using namespace std;
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fo_(i,a,b) for(int i=a;i>=b; --i )
#define sync  std::ios::sync_with_stdio(false);std::cin.tie(0);
typedef long long ll;
#define V vector
const int maxn = 50000;
bool prime[maxn + 1];
void is_p()
{
	memset(prime, 1, sizeof(prime));
	prime[1] = 0;
	for (int i = 2; i * i <= maxn; ++i)
		if (prime[i])
			for (int j = i * i; j <= maxn; j += i)
				prime[j] = 0;
}
int main()
{
	sync;
	int t,n;
	for (cin >> t; t--,cin>>n; cout << endl)
	{
		is_p();
		if (n == 1)cout << 6;
		else if (n == 2)cout << 15;
		else
		{
			int i,j;
			for (i = n + 1; i <= 50000; ++i)
				if (prime[i])
					break;
			for (j = i + n; j <= 50000; ++j)
				if (prime[j])
					break;
			cout << i * j;
 
 
		}
 
 
				
	}
	return 0;
}
