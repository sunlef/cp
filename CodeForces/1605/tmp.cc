struct Node {
    int l, r;
    // TODO: 需要维护的信息和懒标记
} tr[N * 4];

void pushup(int u) {
    // TODO: 利用左右儿子信息维护当前节点的信息
}

void pushdown(int u) {
    // TODO: 将懒标记下传
}

void build(int u, int l, int r) {
    if (l == r)
        tr[u] = {l, r};
    else {
        tr[u] = {l, r};
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

void update(int u, int l, int r, int d) {
    if (tr[u].l >= l && tr[u].r <= r) {
        // TODO: 修改区间
    } else {
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid) update(u << 1, l, r, d);
        if (r > mid) update(u << 1 | 1, l, r, d);
        pushup(u);
    }
}

int query(int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r) {
        return;  // TODO 需要补充返回值
    } else {
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        int res = 0;
        if (l <= mid) res = query(u << 1, l, r);
        if (r > mid) res += query(u << 1 | 1, l, r);
        return res;
    }
}