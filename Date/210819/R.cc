#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string Q[200];
    int now = 1;
    Q[now] = "http://www.acm.org/";
    int maxq = 1;

    string s;
    while (cin >> s) {
        if(s == "VISIT") {
            cin >> Q[maxq = ++now];
            cout << Q[now] << '\n';
        } else if(s == "FORWARD") {
            if(now + 1 > maxq) {
                cout << "Ignored" << '\n';
            } else {
                cout << Q[++now] << '\n';
            }
        } else if(s == "BACK") {
            if(now - 1 < 1) {
                cout << "Ignored" << '\n';
            } else {
                cout << Q[--now] << '\n';
            }
        } else if(s == "QUIT"){
            return 0;
        }
        
    }

    return 0;
}

/***
VISIT https://ntu.edu.cn/
BACK
BACK
FORWARD
VISIT https://www.acwing.com/
VISIT https://www.luogu.com.cn/
VISIT https://www.luogu.com.cn/
VISIT https://www.luogu.com.cn/problem/P7487
FORWARD
TISIV https://www.bilibili.com/video/BV1YK411V7N3
BACK
BACK
BACK
BACK
BACK
FORWARD
BACK
VISIT https://www.bilibili.com/
VISIT https://www.bilibili.com/video/BV1vQ4y1Z7C2
FORWARD
FORWARD
BACK
VISIT https://www.bilibili.com/video/BV1vK4y1p7F5
VISIT https://www.bilibili.com/video/BV1FX4y1g7u8
FORWARD
BACK
QUIT

***/
