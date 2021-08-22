#include<iostream>
using namespace std;
class Complex{
	private: 
		double shibu, xvbu; //实部，虚部
	public:
		Complex(double a, double b){//构造函数
			shibu = a;
			xvbu = b;
		}
		Complex(double a){//「=」号初始化的重载构造函数
			shibu = a;
			xvbu = 0;
		}
		void add(Complex B){//「加」操作
			shibu += B.shibu;
			xvbu += B.xvbu;
		}
		void show(){//「展示」操作
			cout << "(" << shibu << ", " << xvbu << ")" << endl;
		}

};
int main(){
	Complex c1(3,5);
	Complex c2 = 4.5;
	c1.add(c2);
	c1.show();
}
