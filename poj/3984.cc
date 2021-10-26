#include <iostream>
#include <utility>
#include <cstring>

using namespace std;

typedef pair<int, int> pii;
#define MP make_pair
#define X first
#define Y second

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int g[5][5], dis[5][5];

bool check(int x, int y) { return x >= 0 && x < 5 && y >= 0 && y < 5 && g[x][y] != 1; }

int main() {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cin >> g[i][j];
        }
    }

    memset(dis, 0x3f, sizeof dis);
    dis[0][0] = 0;

    pii from[5][5];
    pii queue[100000];
    int front = 0, tail = 0;

    queue[front = ++tail] = MP(0, 0);
    while (front <= tail) {
        int x = queue[front].X;
        int y = queue[front].Y;
        ++front;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (check(nx, ny) && dis[nx][ny] > dis[x][y] + 1) {
                dis[nx][ny] = dis[x][y] + 1;
                queue[++tail] = MP(nx, ny);
                from[nx][ny] = MP(x, y);
            }
        }
    }

    pii ans[100000];
    pii now = MP(4, 4);
    for (int i = dis[4][4] - 1; i >= 0; --i) {
        ans[i] = now;
        now = from[now.X][now.Y];
    }
    cout << "(0, 0)\n";
    for (int i = 0; i < dis[4][4]; ++i) {
        cout << "(" << ans[i].X << ", " << ans[i].Y << ")\n";
    }

    return 0;
}