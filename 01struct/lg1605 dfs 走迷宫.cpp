#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int n, m, t, xt, yt;
int map[10][10], v[10][10];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int ans;
int sx, sy, fx, fy;
void dfs(int x, int y) {
    if (x == fx && y == fy) {
        ans++;
        return;
    }
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 1 && nx <= n
            && ny >= 1 && ny <= m
            && v[nx][ny] == 0 && map[nx][ny] == 1) {
            v[x][y] = 1;
            dfs(nx, ny);
            v[x][y] = 0;
        }
    }
}

int main() {
    cin >> n >> m >> t;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            map[i][j] = 1;
        }
    }
    cin >> sx >> sy >> fx >> fy;
    for (int i = 1; i <= t; i++) {
        cin >> xt >> yt;
        map[xt][yt] = 0;
    }
    dfs(sx, sy);
    cout << ans;
    return 0;
}