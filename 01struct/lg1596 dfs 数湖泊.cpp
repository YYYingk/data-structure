#include<iostream>
using namespace std;
int n, m;
char grid[105][105];
int ans;
void dfs(int x, int y) {
    grid[x][y] = '.';
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if (dx == 0 && dy == 0) continue; // 只跳过原地不动
            int nx = x + dx, ny = y + dy;
            // 判断边界和是否为'W'
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && grid[nx][ny] == 'W') {
                dfs(nx, ny);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> grid[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (grid[i][j] == 'W') {
                ans++;
                dfs(i, j);
            }
        }
    }
    cout << ans;
    return 0;
}