#include<iostream>
#include<cstring>
#include<queue>
#define INF 1001
using namespace std;
int n, m, cnt;
int head[114];
struct Edge {
	int to, w, nex;
}e[11451];
int dis[105], v[105];
typedef pair<int, int> PII;
priority_queue<PII, vector<PII>, greater<PII>> pq;

//void dijkstra(int x) {
//	int u;
//	for (int i = 1; i <= n; i++) {
//		dis[i] = INF;
//	}
//	dis[x] = 0;
//	for (int i = 1; i <= n; i++) {
//		int minn = INF, k = -1;
//		for (int j = 1; j <= n; j++) {
//			if (v[j] == 0 && dis[j] < minn) {
//				minn = dis[j];
//				k = j;
//			}
//		}
//		v[k] = 1;
//		for (int j = head[k]; j != -1; j = e[j].nex) {
//			u = e[j].to;
//			if (!v[u] && dis[u] > dis[k] + e[j].w) {
//				dis[u] = dis[k] + e[j].w;
//			}
//		}
//	}
//}

// ∂—”≈ªØ
void dijkstra(int x) {
	int u;
	for (int i = 1; i <= n; i++) {
		dis[i] = INF;
	}
	dis[x] = 0;
	PII now;
	now.first = dis[x];
	now.second = x;
	pq.push(now);
	while (pq.size()) {
		now = pq.top();
		pq.pop();
		int minn = now.first;
		int k = now.second;
		if (v[k]) continue;
		v[k] = 1;
		for (int j = head[k]; j != -1; j = e[j].nex) {
			u = e[j].to;
			if (dis[u] > minn + e[j].w) {
				dis[u] = minn + e[j].w;
				now.first = dis[u];
				now.second = u;
				pq.push(now);
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
	cin >> n >> m;
	int x, y, wi;
	for (int i = 1; i <= m; i++) {
		cin >> x >> y >> wi;
		add(x, y, wi);
	}
	cin >> x;
	dijkstra(x);
	for (int i = 1; i <= n; i++) {
		cout << dis[i] << " ";
	}
	cout << endl;
	return 0;
}