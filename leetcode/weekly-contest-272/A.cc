#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    bool check(const string &s) {
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] != s[n - i - 1]) {
                return false;
            }
        }
        return true;
    }
    string firstPalindrome(vector<string> &words) {
        for (auto &str : words) {
            if (check(str)) {
                return str;
            }
        }
        return "";
    }
};

int main() { return 0; }