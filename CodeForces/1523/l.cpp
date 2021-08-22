#include <iostream>
#include <string>
using namespace std;
int main()
{
	char a[10];
	cin.getline(a, 6);
	for(int i = 4; i >= 0; --i)
		cout << a[i];
	cout << endl;
}