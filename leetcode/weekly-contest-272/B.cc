#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string res = "";
        int now = 0;
        int n = s.size();

        for (int i = 0; i < n; ++i) {
            if (now < int(spaces.size()) && spaces[now] == i) {
                res.push_back(' ');
                ++now;
            }
            res.push_back(s[i]);
        }
        
        return res;
    }
};

int main() {

    return 0;
}