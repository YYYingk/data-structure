#include<iostream>
using namespace std;
int n, cnt;
int vis[15][114], ans[114];
void dfs(int x) {
    // 只打前三次
    if (x > n) {
        cnt++;
        if (cnt <= 3) {
            for (int i = 1; i <= n; i++) {
                cout << ans[i] << " ";
            }
            cout << endl;
        }
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[1][i] && !vis[2][i + x] && !vis[3][n + i - x]) {
            ans[x] = i;
            vis[1][i] = 1;
            vis[2][i + x] = 1;
            vis[3][n + i - x] = 1;
            dfs(x + 1);
            vis[1][i] = 0;
            vis[2][i + x] = 0;
            vis[3][n + i - x] = 0;
        }
    }
}
int main() {
    cin >> n;
    dfs(1);
    cout << cnt;
    return 0;
}