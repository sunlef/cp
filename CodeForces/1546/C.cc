    /***

        Filename:   C.cc
        Author:     CleanBlue
        Time:       2021-07-12 14:46:37 utc+8
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
    //const int INF = 0x3f3f3f3f;
    const int MAXN = 114514;

    int n;
    int a[SIZE];
    int cnt1[SIZE][2];
    int cnt2[SIZE][2];

    void solve()
    {
        cin >> n;
        memset(cnt1, 0, sizeof cnt1);
        memset(cnt2, 0, sizeof cnt2);

        for (int i = 1; i <= n; ++i)
            cin >> a[i];

        for (int i = 1; i <= n; ++i)
            ++cnt1[a[i]][i % 2];

        sort(a + 1, a + n + 1);

        for (int i = 1; i <= n; ++i)
            ++cnt2[a[i]][i % 2];

        for (int i = 1; i <= n; ++i)
            for (int j = 0; j <= 1; ++j)
                if (cnt1[a[i]][j] != cnt2[a[i]][j]) {
                    cout << "NO" << ENDL;
                    return;
                }

        cout << "YES" << ENDL;
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