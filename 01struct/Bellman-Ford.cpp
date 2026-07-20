#include<iostream>
#define INF 1e6;
using namespace std;
int n, m, s;
struct Edge
{
	int start, end;
	int w;
}e[10005];
int dis[105];

int Bellman_Ford() {
	int u, v, f = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= m; j++) {
			u = e[j].start;
			v = e[j].end;
			if (dis[u] + e[j].w < dis[v]) {
				dis[v] = dis[u] + e[j].w;
				if (i == n) f = 1;
			}
		}
	}
	if (f == 1) return 1;
	return 0;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int x, y, wi;
		cin >> x >> y >> wi;
		e[i].start = x;
		e[i].end = y;
		e[i].w = wi;
	}
	for (int i = 1; i <= n; i++) {
		dis[i] = INF;
	}
	cin >> s;
	dis[s] = 0;
	int j = Bellman_Ford();
	if (j == 1) {
		cout << "有负权回路" << endl;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		cout << dis[i] << " ";
	}
	return 0;
}