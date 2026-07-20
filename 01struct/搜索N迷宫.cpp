#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int n, k;
int ax, ay, bx, by;
char map[114][114];
int v[114][114];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
struct node {
	int x, y;
};

int main() {
	cin >> k;
	while (k--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}
		cin >> ax >> ay >> bx >> by;
		memset(v, 0, sizeof(v));
		if (map[ax][ay] == '#' || map[bx][by] == '#') {
			cout << "NO" << "\n";
			continue;
		}
		queue<node> q;
		v[ax][ay] = 1;
		q.push({ ax, ay });
		while (!q.empty()) {
			node now = q.front();
			q.pop();
			if (now.x == bx && now.y == by) {
				break;
			}
			for (int i = 0; i < 4; i++) {
				int nx = now.x + dx[i];
				int ny = now.y + dy[i];
				if (nx >= 0 && nx < n 
					&& ny >= 0 && ny < n 
					&& !v[nx][ny] && map[nx][ny] == '.') {
					v[nx][ny] = 1;
					q.push({ nx, ny });
				}
			}
		}
		if (v[bx][by] == 1) cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}
	return 0;
}