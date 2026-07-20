#include<iostream>
using namespace std;
int n, k;
char map[10][10];
int ans;
int v[15][15];

void dfs(int line, int placed) {
	if (placed == k) {
		ans++;
		return;
	}
	if (line > n) {
		return;
	}
	// ²»·ÅÆå×Ó
	dfs(line + 1, placed);
	for (int i = 1; i <= n; i++) {
		if (map[line][i] == '#' && v[0][i] == 0) {
			v[0][i] = 1;
			dfs(line + 1, placed + 1);
			v[0][i] = 0;
		}
	}
}

int main() {
	while (cin >> n >> k) {
		if (n == -1 && k == -1) {
			break;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> map[i][j];
			}
		}
		ans = 0;
		memset(v, 0, sizeof(v));
		dfs(1, 0);
		cout << ans << endl;;
	}
	return 0;
}