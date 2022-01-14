#include <bits/stdc++.h>
using namespace std;

template <typename T_vector> void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());
    for (int i = start; i < end; i++) std::cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}

void solve() {
    int N;
    cin >> N;

    vector<int> P(N);
    for (int &i : P) {
    	cin >> i;
    }

    string S;
    cin >> S;

    vector<pair<int, int>> dislike, like;

    for (int i = 0; i < N; ++i) {
    	if (S[i] == '0') {
    		dislike.push_back({P[i], i});
    	} else {
    		like.push_back({P[i], i});
    	}
    }

    ranges::sort(dislike), ranges::sort(like);

    vector<int> ans(N);
    int pos = 1;

    for (auto &[p, idx] : dislike) {
    	ans[idx] = pos++;
    }

    for (auto &[p, idx] : like) {
    	ans[idx] = pos++;
    }

    output_vector(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int TwT = 1; TwT <= T; ++TwT) {
        solve();
    }

    return 0;
}