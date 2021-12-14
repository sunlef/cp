#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector grid(n, std::vector(n, 1));

    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            grid[i][j] = 0;
            if (i - 1 >= 0) {
            	grid[i][j] += grid[i - 1][j - 1];
            	if (j < i) {
            		grid[i][j] += grid[i - 1][j];
            	}
            }
        }
    }

    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j <= i; ++j) {
    		std::cout << grid[i][j] << " \n"[j == i];
    	}
    }

    return 0;
}