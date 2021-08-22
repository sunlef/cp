#include<iostream>
#include<string>
using namespace std;
int main(){
	long double sum = 0;
	string s;
	int x;
	int cnt;
	ios::sync_with_stdio(0); cin.tie(0);
	while(cin >> s && s[0] != '0'){
		cin >> x >> cnt;
		if(s[0] == 'X'){
			cnt = cnt+1 >> 1;
			sum += x * cnt;
		}	
		else if(s[0] == 'Y'){
			sum += (cnt+1 >> 1) * x;
			sum += 1.0 * (cnt - (cnt+1 >> 1)) * x / 2;
		}
		else sum += cnt*x;
	}
	cout << sum << '\n';
}
