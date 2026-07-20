#include<iostream>
#include<queue>
using namespace std;
int n, m;
char map[305][305];
int v[305][305];
struct node {
    int x, y;
    int t;
};
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
queue<node> q;
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> map[i][j];
            if (map[i][j] == '@') {
                q.push({ i, j, 0 });
                v[i][j] = 1;
            }
        }
    }
    while (!q.empty()) {
        node p = q.front();
        q.pop();
        if (map[p.x][p.y] == '=') {
            cout << p.t;
            break;
        }
        for (int i = 0; i < 4; i++) {
            int nx = p.x + dx[i];
            int ny = p.y + dy[i];
            if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if (map[nx][ny] == '#') continue;
            if ((map[nx][ny] == '.' || map[nx][ny] == '=') && !v[nx][ny]) {
                q.push({ nx, ny, p.t + 1 });
                v[nx][ny] = 1;
            }
            if (map[nx][ny] >= 'A' && map[nx][ny] <= 'Z') {
                char c = map[nx][ny];
                if (!v[nx][ny]) {
                    v[nx][ny] = 1;
                    for (int i = 1; i <= n; i++) {
                        for (int j = 1; j <= m; j++) {
                            if (map[i][j] == c && !(i == nx && j == ny)) {
                                // 考虑到这个传送阵只是另外一种形式的障碍
                                // （也就是不得不踩进去的情况，故此传送阵另一端不能设置为已探，
                                // 如果设置将会导致我们不能再次回来（因为不能连续传，必须出去一次，但出去一次就不能再回来了）
                                // 但如果是从此传送阵的另一端第二次回到这一端，那么我们仍按照访问过来处理，即第44行的处理）
                                q.push({ i, j, p.t + 1 });
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}