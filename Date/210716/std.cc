#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[4];
int b[4];
int c[4];
int right(int a, int p)
{
	if (a >> (3 - p) & 1)
		return 1;
	else
		return 0;
}
void shangse(int arr[], int x, int y)
{
	arr[x] = arr[x] | (1 << (3 - y));
}
void flip(int arr[], int x, int y)
{
	arr[x] = arr[x] ^ (1 << (3 - y));
	if (x - 1 >= 0)
		arr[x - 1] ^= 1 << (3 - y);
	if (y - 1 >= 0)
		arr[x] ^= 1 << (3 - y + 1);
	if (x + 1 <= 3)
		arr[x + 1] ^= 1 << (3 - y);
	if (y + 1 <= 3)
		arr[x] ^= 1 << (3 - y - 1);
}
int i, j, b_bushu, c_bushu, minbushu = 99999;
char s[20];
int main()
{
	//freopen("input2.txt","r",stdin);
	for (i = 0; i < 4; i++) {
		scanf("%s", s);
		for (j = 0; j < 4; j++) {
			if (s[j] == 'b')
				shangse(a, i, j);
		}
	}
	//ceshi
	//for(int k=0;k<4;k++){
	//  cout<<a[k]<<endl;
	//}
	//end
	for (i = 0; i < 16; i++) {
		b_bushu = 0;
		for (j = 0; j < 4; j++)
			b[j] = a[j];
		///  sixteen  manipulates
		for (j = 0; j < 4; j++) {
			if (right(i, j))  ///  the j position is 1 : flip
			{
				flip(b, 0, j);
				b_bushu++;
			}
		}  ///  the o row is already
		for (int j = 0; j < 4; j++) {
			c[j] = b[j];
			//cout<<"  c[]"<<c[j]<<endl;
		}  ///   c  is ready
		c_bushu = b_bushu;
		for (int m = 1; m < 4; m++) {
			for (int n = 0; n < 4; n++) {
				if (right(b[m - 1], n)) {
					flip(b, m, n);
					b_bushu++;
				}
				if (!right(c[m - 1], n)) {
					flip(c, m, n);
					c_bushu++;
				}
			}
		}
		if (b[0] == 0 && b[0] == b[1] && b[1] == b[2] && b[2] == b[3])  ///   is the same
		{
			minbushu = min(minbushu, b_bushu);
		}
		if (c[0] == 15 && c[0] == c[1] && c[1] == c[2] && c[2] == c[3])  ///   is the same
		{
			minbushu = min(minbushu, c_bushu);
		}
	}
	if (minbushu == 99999) {
		cout << "Impossible\n";
		return 0;
	}
	cout << minbushu << endl;
	return 0;
}