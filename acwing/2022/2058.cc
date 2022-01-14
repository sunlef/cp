#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string BIN, TER;
    cin >> BIN >> TER;

    auto bin_to_dec = [&](const string &bin) -> int64_t {
        int64_t dec = 0;
        int64_t base = 1;
        for (int i = int(bin.size()) - 1; i >= 0; --i) {
            dec += base * (bin[i] == '1');
            base *= 2;
        }
        return dec;
    };

    auto bin_to_ter = [&](const string &bin) -> string {
        int64_t dec = bin_to_dec(bin);
        string res;
        while (dec) {
            int remainder = dec % 3;
            dec /= 3;
            res.push_back(remainder + '0');
        }
        return string(res.rbegin(), res.rend());
    };

    auto valid = [&](const string &lhs, const string &rhs) -> bool {
        if (lhs.size() != rhs.size()) {
            return false;
        }
        int diff = 0;
        for (int i = 0; i < int(lhs.size()); ++i) {
            if (lhs[i] != rhs[i]) {
                ++diff;
            }
        }
        return diff == 1;
    };

    for (int i = 0; i < int(BIN.size()); ++i)  {
        string now = BIN;
        now[i] = !(now[i] - '0') + '0';
        if (valid(bin_to_ter(now), TER)) {
            cout << bin_to_dec(now) << '\n';
            return 0;
        }
    }

    return 0;
}