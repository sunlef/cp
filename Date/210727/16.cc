#include<iostream>
#include<string>
using namespace std;
int main()
{
    int a;//输入的数
    int y = 0;
    string s = "";
    cin >> a;
    if (a == 0)
    {
        cout << 0;
        return 0;
    }
    while (a > 0) 
    {
        y = a % 16;
        if (y < 10)
        {
            s = char('0' + y) + s;
        }
        else
        {
            s = ('A' - 10 + y) + s;
        }
        a = a / 16;
    }
    cout << s;
    
}