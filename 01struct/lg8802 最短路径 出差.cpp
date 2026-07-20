#include<iostream>
#include<cstring>
#include<queue>
#define INF 1e9;
using namespace std;
int n, m, cnt, ans, c[1005];
int head[1005];
struct Edge {
	int to, w, nex;
}e[20005];
int dis[1005], v[1005];

//typedef pair<int, int> PII;
//priority_queue<PII, vector<PII>, greater<PII>> pq;
//// ∂—”≈ªØ
//void dijkstra(int x) {
//	int u;
//	for (int i = 1; i <= n; i++) {
//		dis[i] = INF;
//	}
//	dis[x] = 0;
//	PII now;
//	now.first = dis[x];
//	now.second = x;
//	pq.push(now);
//	while (pq.size()) {
//		now = pq.top();
//		pq.pop();
//		int minn = now.first;
//		int k = now.second;
//		if (v[k]) continue;
//		v[k] = 1;
//		for (int j = head[k]; j != -1; j = e[j].nex) {
//			u = e[j].to;
//			if (dis[u] > minn + e[j].w) {
//				dis[u] = minn + e[j].w;
//				now.first = dis[u];
//				now.second = u;
//				pq.push(now);
//			}
//		}
//	}
//}

void SPFA(int x) {
	for (int i = 1; i <= n; i++) {
		dis[i] = INT_MAX;
	}
	queue<int> q;
	dis[x] = 0;
	q.push(x);
	v[x] = 1;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		v[now] = 0;
		for (int i = head[now]; i != -1; i = e[i].nex) {
			int k = e[i].to;
			if (dis[k] > dis[now] + e[i].w) {
				dis[k] = dis[now] + e[i].w;
				if (v[k] == 0) {
					q.push(k);
					v[k] = 1;
				}
			}
		}
	}
}

void add(int x, int y, int w) {
	e[cnt].w = w;
	e[cnt].to = y;
	e[cnt].nex = head[x];
	head[x] = cnt;
	cnt++;
}

int main() {
	memset(head, -1, sizeof(head));
	memset(dis, 0x3f, sizeof(dis));
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	int x, y, wi;
	for (int i = 1; i <= m; i++) {
		cin >> x >> y >> wi;
		add(x, y, wi + c[y]);
		add(y, x, wi + c[x]);
	}
	//dijkstra(1);
	SPFA(1);
	cout << dis[n] - c[n];
	return 0;
}