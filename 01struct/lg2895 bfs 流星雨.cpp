#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int m;
int map[305][305], v[305][305], ans[305][305];
int mx, my, mt;
int dx[5] = { 0,0,0,1,-1 };
int dy[5] = { 0,1,-1,0,0 };//方便移动和处理陨石砸落
struct node {
    int x, y;
};
int pan(int z) {
    if (z == -1)return 114514;
    return z;
}
int main() {
    memset(map, -1, sizeof(map));
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d %d", &mx, &my, &mt);
        for (int j = 0; j < 5; j++) {//上下左右中标记陨石
            //如果该标记x,y坐标大于0且该点没有被陨石砸落或已标记时间没有该时间早，标记陨石
            if (mx + dx[j] >= 0
                && my + dy[j] >= 0
                && (map[mx + dx[j]][my + dy[j]] == -1
                    || map[mx + dx[j]][my + dy[j]] > mt))
                map[mx + dx[j]][my + dy[j]] = mt;
        }
    }
    queue<node> q;
    v[0][0] = 1;
    q.push({ 0, 0 });
    while (!q.empty()) {
        node p = q.front();
        q.pop();
        // 即将标记的点时间是现在点的下一个单位
        int s = ans[p.x][p.y] + 1;
        if (map[p.x][p.y] == -1) {
            printf("%d\n", s - 1);
            return 0;
        }
        for (int i = 1; i < 4; i++) {
            int nx = p.x + dx[i];
            int ny = p.y + dy[i];
            if (nx >= 0 && ny >= 0 && v[nx][ny] == 0 && pan(map[nx][ny]) > s) {
                q.push({ nx, ny });
                v[nx][ny] = 1;
                ans[nx][ny] = s;
            }
        }
    }
    printf("-1\n");
    return 0;
}