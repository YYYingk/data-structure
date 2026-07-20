#include<iostream>
#include<string>
using namespace std;
int n;
char a[105][105];
int b[105][105];
string c = "yizhong";

void dfs(int nx, int ny, int x, int y, int z) {
    if (z >= 7) {
        for (int i = 1; i <= 7; i++) b[x - nx * i][y - ny * i] = 1;
    }
    if (x >= 1 && y >= 1 && x <= n && y <= n && a[x][y] == c[z])
        dfs(nx, ny, x + nx, y + ny, z + 1);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == 'y') {
                for (int di = -1; di <= 1; di++) {
                    for (int dj = -1; dj <= 1; dj++) {
                        if (a[i + di][j + dj] == 'i') {
                            dfs(di, dj, i, j, 0);
                        }
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (b[i][j] != 1) cout << '*';
            else cout << a[i][j];
        }
        cout << endl;
    }
    return 0;
}