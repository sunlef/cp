    /***

        Filename:   B.cpp
        Author:     CleanBlue
        Time:       2021-06-05 19:05:58 utc+8
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

    template <class T>
    void _R(T& x)
    {
        cin >> x;
    }
    void _R(int& x) { scanf("%d", &x); }
    void _R(int64_t& x) { scanf("%lld", &x); }
    void _R(double& x) { scanf("%lf", &x); }
    void _R(char& x) { scanf(" %c", &x); }
    void _R(char* x) { scanf("%s", x); }
    void READ() {}
    template <class T, class... U>
    void READ(T& head, U&... tail)
    {
        _R(head);
        READ(tail...);
    }
    template <class T>
    void _W(const T& x)
    {
        cout << x;
    }
    void _W(const int& x) { printf("%d", x); }
    void _W(const int64_t& x) { printf("%lld", x); }
    void _W(const double& x) { printf("%.16f", x); }
    void _W(const char& x) { putchar(x); }
    void _W(const char* x) { printf("%s", x); }
    template <class T, class U>
    void _W(const pair<T, U>& x)
    {
        _W(x.first);
        putchar(' ');
        _W(x.second);
    }
    template <class T>
    void _W(const vector<T>& x)
    {
        for (auto i = x.begin(); i != x.end(); _W(*i++))
            if (i != x.cbegin())
                putchar(' ');
    }
    void WRITE() {}
    template <class T, class... U>
    void WRITE(const T& head, const U&... tail)
    {
        _W(head);
        putchar(sizeof...(tail) ? ' ' : '\n');
        WRITE(tail...);
    }

    //const double PI = acos(-1.0);
    //const double EPS = 1e-6;
    //const int INF = 0x3f3f3f3f;
    const int MAXN = 204514;

    int k, n;
    priority_queue<int> q;

    void solve()
    {
        while (q.size())
            q.pop();
        READ(n, k);

        for (int i = 1; i <= n; ++i) {
            int x;
            READ(x);
            q.push(x);
        }
        while (k--) {
            if (q.size() == 1) {
                WRITE(q.top());
                return;
            }
            int x = q.top();
            q.pop();
            int y = q.top();
            q.pop();
            x += y;
            q.push(x);
        }
        WRITE(q.top());
    }

    int main()
    {
        int T;
        READ(T);

        while (T--)
            solve();

        return 0;
    }