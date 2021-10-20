#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a = 233, b = 666, c = 777;
    int n = 5;

    vector<int> vec(n);
    vec[0] = 2, vec[1] = 3, vec[2] = 5, vec[3] = 7, vec[4] = 11;

    vector<string> vec2(3);
    vec2[0] = "what", vec2[1] = "the", vec2[2] = "fxxk?";

    string s = "hello world";

    debug(a, b, c, n, vec, vec2, s);

    return 0;
}


