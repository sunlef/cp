#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64_t x, y;
    cin >> x >> y;

    auto to_string = [](int64_t x) -> string {
        string res;
        while (x) {
            res.push_back('0' + (x & 1));
            x >>= 1;
        }
        ranges::reverse(res);
        return res;
    };

    auto add_one = [](string str) -> string {
        str.push_back('1');
        ranges::reverse(str);
        return str;
    };

    auto add_zero = [](string str) -> string {
        while (str.back() == '0') {
            str.pop_back();
        }
        ranges::reverse(str);
        return str;
    };

    set<string> visited;

    string st = to_string(x), ed = to_string(y);
    bool ok = false;

    auto failed = [&] (string str) -> bool {
    	int64_t A = 0, B = 0;
    	int64_t now = 1;
    	for (auto &ch : str) {
    		if (ch == '1') {
    			A += now;
    		}
    		now *= 2;
    	}
    	ranges::reverse(str);
    	now = 1;
    	for (auto &ch : str) {
    		if (ch == '1') {
    			B += now;
    		}
    		now *= 2;
    	}
    	return (A > y && B > y);
    };

    function<void(string)> dfs = [&](string A) -> void {
        if (A == ed) {
            ok = true;
            return;
        }

        if (failed(A)) {
        	return;
        }

        visited.insert(A);

        string B = add_one(A);
        string C = add_zero(A);

        if (!visited.count(B)) {
            dfs(B);
        }

        if (ok) {
            return;
        }

        if (!visited.count(C)) {
            dfs(C);
        }
    };

    dfs(st);

    cout << (ok ? "YES\n" : "NO\n");

    return 0;
}