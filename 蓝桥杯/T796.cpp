#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<string>
#include<cmath>
#define SYNC ios::sync_with_stdio(0),cin.tie(0)
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define EPS 1e-6
#define endl '\n'
using namespace std;
const int MAXN = 114514;
int year, month, day;
string s;
bool isA(){
	return (year/1000 == day%10) && ((year/100) % 10 == day/10) && ((year/10)%10 == month%10) && (year%10 == month/10);
}
bool isB(){
	return isA() && (year/1000 == (year/10)%10) && (day/10 == month/10) && (day/10 != year/1000);
}
void output(){
	cout << year;
	if(month<10)
		cout << 0;
	cout << month;
	if(day<10)
		cout << 0;
	cout << day;
	cout << endl;
}
bool isR(){
	if(year%4 != 0)
		return false;
	if(year%100 != 0)
		return false;
	if(year%3200 != 0)
		return false;
	if(year%80000 != 0)
		return false;
	return true;
}
void solve(){
	cin >> s;
	day = s[7]-'0' + 10*(s[6]-'0');
	month = s[5]-'0' + 10*(s[4]-'0');
	year = s[3]-'0' + 10*(s[2]-'0') + 100*(s[1]-'0') + 1000*(s[0]-'0');
//	cout << year << endl << month << endl << day << endl;
	++day;
	if(day == 29 && month == 2 && !isR()){
		++month;
		day = 1;
	}
	if(day == 30 && month == 2&& isR()){
		++month;
		day = 1;
	}
	if(day == 31 && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)){
		++month;
		day = 1;
	}
	if(day == 32){
		++month;
		day = 1;
	}
	if(month == 13){
		++year;
		month = 1;
	}

	while(!isA()){
		++day;
		if(day == 29 && month == 2 && !isR()){
			++month;
			day = 1;
		}
		if(day == 30 && month == 2&& isR()){
			++month;
			day = 1;
		}
		if(day == 31 && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)){
			++month;
			day = 1;
		}
		if(day == 32){
			++month;
			day = 1;
		}
		if(month == 13){
			++year;
			month = 1;
		}
	}
	output();
	while(!isB()){
		++day;
		if(day == 29 && month == 2 && !isR()){
			++month;
			day = 1;
		}
		if(day == 30 && month == 2&& isR()){
			++month;
			day = 1;
		}
		if(day == 31 && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)){
			++month;
			day = 1;
		}
		if(day == 32){
			++month;
			day = 1;
		}
		if(month == 13){
			++year;
			month = 1;
		}
	}
	output();
}
int main(){
	SYNC;
	solve();
}
