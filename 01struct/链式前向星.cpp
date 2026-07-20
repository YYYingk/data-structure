#include<iostream>
#include<cstring>
using namespace std;
int n, m; // n个顶点, m条边
int head[105];
int v[105];
struct Edge {
	int to;
	int w;
	int nex;
} e[10005];

int cnt;
static void add(int x, int y, int wi) {
	// 模拟头插 
	e[cnt].nex = head[x];
	e[cnt].to = y;
	e[cnt].w = wi;
	head[x] = cnt;
	cnt++;
}

static void dfs(int x) {
	if (v[x]) return;
	cout << x << " ";
	v[x] = 1;
	for (int i = head[x]; i != -1; i = e[i].nex) {
		int y = e[i].to;
		dfs(y);
	}
}

int main() {
	cin >> n >> m;
	memset(head, -1, sizeof(head));
	int x, y, wi;
	for (int i = 1; i <= m; i++) {
		cin >> x >> y >> wi;
		add(x, y, wi);
		add(y, x, wi);
	}
	for (int i = 1; i <= n; i++) {
		if (!v[i]) {
			dfs(i);
		}
	}
	return 0;
}