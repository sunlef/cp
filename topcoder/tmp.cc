#include <bits/stdc++.h>
using namespace std;

class AB {
    public:
    string createString(int N, int K) {
        if (N == 0) {
            return string();
        } else if (K == 0) {
            return string(N, 'A');
        } else if (2 * K > N) {
            return string();
        } else {
            string ans;
            while (N > 2) {
                ans += "AB";
                N -= 2;
            }
            if (N) {
                ans += 'B';
            }
            return ans;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    AB ab;
    cout << ab.createString(3, 2) << '\n';
    return 0;
}