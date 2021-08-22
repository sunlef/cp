#include<iostream>
using namespace std;
int a[100];
int main ()
{
	memset(a, -0x3f3f3f3f, sizeof(a) );
	for(int i = 1; i <= 10; ++i)
		cout << a[i] << endl;
	cout << -0x3f3f3f3f << endl;
}	
