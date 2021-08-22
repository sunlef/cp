    /***

        Filename:   A.cc
        Author:     CleanBlue
        Time:       2021-07-13 09:56:58 utc+8
        Site:       cleanblue.moe

    ***/
    #include <algorithm>
    #include <cmath>
    #include <cstdio>
    #include <cstring>
    #include <deque>
    #include <iostream>
    #include <map>
    #include <queue>
    #include <set>
    #include <stack>
    #include <string>
    #include <vector>

    #define ENDL '\n'
    #define SIZE MAXN
    #define DIV  cout << "\n==============================\n"

    using namespace std;
    typedef long long LoveLive;
    typedef long double LD;
    typedef unsigned long long ULL;
    typedef LoveLive LL;
    typedef pair<int, int> PII;
    typedef pair<LoveLive, int> PLI;
    typedef pair<LoveLive, LoveLive> PLL;

    //const double PI = acos(-1.0);
    //const double EPS = 1e-6;
    const int INF = 0x3f3f3f3f;
    const int MAXN = 114514;

    string s;

    void solve()
    {
        cin >> s;

        char maxx = 'a';
        int l = 0, r = s.size() - 1;
        for (int i = l; i <= r; ++i)
            maxx = max(maxx, s[i]);

        maxx += 1;
        while (l <= r) {
            maxx -= 1;
            if (s[l] == maxx) {
                ++l;
                continue;
            }
            else if (s[r] == maxx) {
                --r;
                continue;
            }
            cout << "NO" << ENDL;
            return;
        }

        if (maxx != 'a') {
            cout << "NO" << ENDL;
            return;
        }

        cout << "YES" << ENDL;
        return;
    }

    int main()
    {
        ios::sync_with_stdio(0);
        cin.tie(0);

        int T = 1;
        cin >> T;
        while (T--)
            solve();

        return 0;
    }