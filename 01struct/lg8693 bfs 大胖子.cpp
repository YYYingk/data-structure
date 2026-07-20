#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
struct node {
    int x, y;
    int t; // 时间
    int r; // 小明的体积半径 0:1*1ge
};
int n, k;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };
char map[514][514];
int v[514][514];
queue<node> q;

bool check(int nx, int ny, int r) {
    if (v[nx][ny] == 1) return 0;
    for (int i = nx - r; i <= nx + r; i++) {
        for (int j = ny - r; j <= ny + r; j++) {
            if (i<1 || i>n || j<1 || j>n || map[i][j] == '*') return 0;
        }
    }
    return 1;
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> map[i][j];
        }
    }
    v[3][3] = 1;
    q.push((node) { 3, 3, 0, 2 });
    int r;
    while (!q.empty()) {
        node p = q.front();
        q.pop();
        if (p.x == n - 2 && p.y == n - 2) {
            cout << p.t << endl;
            break;
        }
        if (p.r != 0) {
            // 原地等待
            if (p.t + 1 < k) r = 2;
            else if (p.t + 1 < 2 * k) r = 1;
            else r = 0;
            q.push((node) { p.x, p.y, p.t + 1, r });
        }
        node nex;
        for (int i = 0; i < 4; i++) {
            nex.x = p.x + dx[i];
            nex.y = p.y + dy[i];
            if (check(nex.x, nex.y, p.r)) {
                v[nex.x][nex.y] = 1;
                nex.t = p.t + 1;
                if (p.t + 1 < k) nex.r = 2;
                else if (p.t + 1 < 2 * k) nex.r = 1;
                else nex.r = 0;
                q.push(nex);
            }
        }
    }
    return 0;
}