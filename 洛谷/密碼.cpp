#include<iostream>
#include<string>
using namespace std;
int main(){
	string str;
	getline(cin, str);
	cout << "加密前：" << str << endl;
	cout << "加密后：";
	for(int i = 0; i < str.size(); ++i){
		if(str[i] >= 'a' && str[i] <= 'z')
			cout << (char) ( ( (str[i]-'a') + 1) % 26 +'a');
		else if(str[i] >= 'A' && str[i] <= 'Z')
			cout << (char) ( ( (str[i]-'A') + 1) % 26 +'A');
		else
			cout << str[i];
	}
	cout << endl;
}
