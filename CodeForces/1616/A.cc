#include <bits/stdc++.h>
using namespace std;

struct Node {
    int n, m;  // 这一结点的行号、列号
    string S;  // 这一结点到目前位置的行走方案
} start;

bool success;
string ans;

void output_path(const vector<vector<char>> &grid, const string &solution) {
    auto show_grid = grid;
    int X = start.n, Y = start.m;

    for (char ch : solution) {
        if (show_grid[X][Y] == '.') {
            show_grid[X][Y] = ch;
        }

        if (ch == 'U') {
            --X;
        } else if (ch == 'D') {
            ++X;
        } else if (ch == 'L') {
            --Y;
        } else {
            ++Y;
        }
    }

    for (auto &row : show_grid) {
        for (auto &ch : row) {
            cout << ch;
        }
        cout << '\n';
    }
}

void bfs(const vector<vector<char>> &grid, int N, int M) {
    success = false;
    queue<Node> Q;  //定义队列

    vector<tuple<int, int, char>> moves = {{-1, 0, 'U'}, {1, 0, 'D'}, {0, -1, 'L'}, {0, 1, 'R'}};  // 方向数组

    vector<vector<bool>> visited(N, vector<bool>(M, false));  //标记格子是否走过

    Q.push(start);                     //将起点状态入队
    visited[start.n][start.m] = true;  //将起点标记为走过

    while (!Q.empty()) {             //当队列不为空时搜索
        auto [n, m, S] = Q.front();  //当前队首
        Q.pop();                     //将当前状态出队

        if (grid[n][m] == 'E') {  //如果走到了终点
            ans = S;
            success = true;
            return;
        }

        for (auto [dx, dy, dc] : moves) {  //枚举四个方向
            int X = n + dx, Y = m + dy;    //X, Y是从当前格子朝着这个方向走一步之后的格子

            if (X < 0 || X >= N || Y < 0 || Y >= M) {  //排除格子出界的情况
                continue;
            }
            if (grid[X][Y] == '#') {  //排除走到墙壁的情况
                continue;
            }
            if (visited[X][Y]) {  //排除重复入队的情况
                continue;
            }

            visited[X][Y] = true;    //将当前格子标记为访问过
            Q.push({X, Y, S + dc});  //将新状态入队
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    if (N <= 0 || M <= 0) {
        cout << "Wrong Input!\n";
        return 0;
    }

    vector<vector<char>> grid(N, vector<char>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 'S') {  //若为起点
                start = {i, j, string()};
            }
        }
    }

    for (auto &row : grid) {
        for (auto &ch : row) {
            if (ch != '.' && ch != '#' && ch != 'S' && ch != 'E') {
                cout << "Wrong Input!\n";
                return 0;
            }
        }
    }

    bfs(grid, N, M);

    if (!success) {
        cout << "No Answer\n";
    } else {
        cout << "--------------\nSolution is: " << ans << '\n';
        cout << "--------------\nThe Path is:\n";
        output_path(grid, ans);
    }

    return 0;
}