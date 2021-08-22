#include <iostream>
using namespace std;
int main()
{
	cout<<"第1题：预测函数输出结果"<<endl;
	cout<<"交运2001班 06 罗玮轩"<<endl;
	{
		cout<<"程序一的预测：输出 4"<<;
			int k=2,m=2,n=6;
			int *pk=&k,*pm=&m,*p;
			*(p=&n) = *pk * (*pm);
			cout<<n<<endl;
			cout<<"本质：n=k*m"<<endl;
		}
		{
			cout<<"程序二预测：输出 5,5,5 i的地址"<<;
			int i,*pi;
			pi=&i;
			i=5;
			cout<<"\n"<<i<<','<<*pi<<','<<*&i; 
			cout<<"\n"<<&i<<','<<pi<<','<<&*pi;
			cout<<"本质：输出值，输出i的地址"<<endl;
		}
		{
			cout<<"程序三预测：输出111122223333"<<;
			int a[]={1,2,3};
			int *p,i;
			p=a;
			for(i=0;i<3;i++)
			cout<<a[i]<<p[i]<<*(p+i)<<*(a+i);
		    cout<<"本质：输出数组a的值，输出数组a的值"<<endl;
		}
		return 0;
}
