#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;  //迷宫的行数和列数
    std::cin >> n >> m;

    int S_row, S_col, E_row, E_col;  //起点和终点的位置

    std::vector<std::vector<char>> grid(n, std::vector<char>(m));
    for (int i = 0; i < n; ++i) {  //读入迷宫
        for (int j = 0; j < m; ++j) {
            char &ch = grid[i][j];
            std::cin >> ch;
            if (ch == 'S') {
                S_row = i, S_col = j;
            } else if (ch == 'E') {
                E_row = i, E_col = j;
            }
        }
    }

    std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));

    int dx[] = {-1, 0, 0, 1};  //方向数组
    int dy[] = {0, -1, 1, 0};

    std::function<bool(int, int, int)> check = [&](int x, int y, int d) -> bool {  //判断该方向是否可走
        int nx = x + dx[d], ny = y + dy[d];
        return nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '#' && !visited[nx][ny];
    };

    std::function<std::string()> bfs = [&]() -> std::string {  //bfs函数
        std::queue<std::tuple<int, int, std::string>> q;       //定义队列

        q.push({S_row, S_col, ""});    //将起点入队
        visited[S_row][S_col] = true;  //将起点标记为已走过

        while (!q.empty()) {  //队列非空时进行搜索
            int now_row = std::get<0>(q.front());
            int now_col = std::get<1>(q.front());
            std::string now_path = std::get<2>(q.front());
            q.pop();  //当前节点出队

            if (now_row == E_row && now_col == E_col) {  //当第一次走到终点时，由于是bfs（等价与权值为1的最短路），所以是最短路径。
                return "This maze could be solved in " + std::to_string(now_path.size()) + " step(s), the solution is:\n" + now_path;
            }

            for (int i = 0; i < 4; ++i) {  //枚举四个方向
                if (check(now_row, now_col, i)) {
                    int new_row = now_row + dx[i];  //计算新位置
                    int new_col = now_col + dy[i];
                    std::string new_path = now_path + "ULRD"[i];  //计算新路径

                    visited[new_row][new_col] = true;  //标记已走过
                    q.push({new_row, new_col, new_path});
                }
            }
        }

        return "impossible";
    };

    std::cout << bfs() << '\n';  //输出答案
    return 0;
}
/*
10 10
S...######
.####...##
......#..#
####.###.#
...E#....#
###.###...
......#...
#.#####.##
....#.....
.#....#...
*/