#include <bits/stdc++.h>
using namespace std;

constexpr int SIZE = 1e5;
constexpr int seg_SIZE = 4 << __lg(SIZE);
constexpr int ls(int x) { return 2 * x; }
constexpr int rs(int x) { return 2 * x + 1; }

struct Node {
    int a, b, c, ab, bc, abc;
    Node() {}
    Node(char ch) : a(ch == 'a'), b(ch == 'b'), c(ch == 'c') {}
};

string s;
int n;
Node info[seg_SIZE];

Node operator+(const Node& lhs, const Node& rhs) {
    Node res;
    res.a = lhs.a + rhs.a;
    res.b = lhs.b + rhs.b;
    res.c = lhs.c + rhs.c;
    res.ab = min(lhs.ab + rhs.b, lhs.a + rhs.ab);
    res.bc = min(lhs.bc + rhs.c, lhs.b + rhs.bc);
    res.abc = min({lhs.a + rhs.abc, lhs.ab + rhs.bc, lhs.abc + rhs.c});
    return res;
}

void pull(int u) { info[u] = info[ls(u)] + info[rs(u)]; }

void build(int u, int l, int r) {
    if (r - l == 1) {
        info[u] = Node(s[l]);
    } else {
        int mid = (l + r) / 2;
        build(ls(u), l, mid);
        build(rs(u), mid, r);
        pull(u);
    }
}
void build() { build(1, 0, n); }

void modify(int u, int l, int r, int pos, char ch) {
    if (r - l == 1) {
        info[u] = ch;
    } else {
        int mid = (l + r) / 2;
        if (pos < mid) {
            modify(ls(u), l, mid, pos, ch);
        } else {
            modify(rs(u), mid, r, pos, ch);
        }
        pull(u);
    }
}
void modify(int pos, char ch) { modify(1, 0, n, pos, ch); }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> n >> q;
    cin >> s;

    build();

    while (q--) {
        int pos;
        char ch;
        cin >> pos >> ch;
        --pos;

        modify(pos, ch);
        cout << info[1].abc << '\n';
    }

    return 0;
}