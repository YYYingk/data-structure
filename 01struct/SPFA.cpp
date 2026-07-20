#include<iostream>
#include<cstring>
#include<queue>
#include<climits>

#define ll long long
using namespace std;
int n, m, cnt, s;
int head[114514];
struct Edge {
	int to, w, nex;
}e[1145141];
ll dis[114514];
int cur[114514];
int v[114514];

bool SPFA(int x) {
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
				cur[k] = cur[now] + 1;
				if (v[k] == 0) {
					q.push(k);
					v[k] = 1;
				}
			}
		}
	}
	return 1;
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
	cin >> n >> m >> s;
	int x, y, wi;
	for (int i = 1; i <= m; i++) {
		cin >> x >> y >> wi;
		add(x, y, wi);
	}
	int ans = INT_MAX;
	if (SPFA(s) == 0) {
		cout << ans << endl;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		cout << dis[i] << " ";
	}
	cout << endl;
	return 0;
}