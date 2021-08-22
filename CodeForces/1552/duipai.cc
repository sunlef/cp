#include<cstdlib>
#include<ctime>
#include<cstdio>
#include<iostream>
using namespace std;
int main(){
    for(int i = 1; i <= 100000; ++i){
        cout << "=======";
        system("./test > test.out");
        double st = clock();
        system("./c < test.out > c.out");
        double ed = clock();
        cout << "第" << i << "组数据=======" << endl << "我的用时：" << ed-st << "ms. \n";
        st = clock();
        system("./sdh <test.out >std.out");
        ed = clock();
        cout << "std 用时：" << ed-st << "ms. \n";
        cout << "结果：";
        if(system("diff std.out c.out")){
            cout << "Wrong Answer !" << endl;
            cout << "样例：" << endl;
            system("cat test.out");
            cout << "我的输出：" << endl;
            system("cat c.out");
            cout << "std 输出：" << endl;
            system("cat std.out");
            break;
        }
        else cout << "Accept !" << endl;
    }

}