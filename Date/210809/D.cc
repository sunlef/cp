#include<cstdio>
#include<vector>
#include<string>
#include<iostream>
using namespace std;
class OrAndSum {
public:
    string tak = "Possible", nie = "Impossible";
    bool check(int k, int x, vector < long long > a, vector < long long > b) {
        for (int i = 0; i < a.size(); ++i) {
            int _or = (a[i] >> k) & 1; int _and = (b[i] >> k) & 1;
            if (_or && !_and)
                x ^= 1;
            if (_or && _and && !x)
                return false;
            if (!_or && _and)
                return false;
            if (!_or && !_and && x)
                return false;
        } return true;
    }
    string isPossible(vector < long long > pairOr, vector < long long > pairSum) {
        vector < long long > &a = pairOr, &b = pairSum;
        for (int i = 0; i < b.size(); ++i) b[i] -= a[i];
        for (int i = 0; i < b.size(); ++i) if (b[i] < 0) return nie;
        for (int j = 0; j < 64; ++j)
            if ((!check(j, 0, a, b)) && (!check(j, 1, a, b)))
                return nie;
        return tak;
    }
};