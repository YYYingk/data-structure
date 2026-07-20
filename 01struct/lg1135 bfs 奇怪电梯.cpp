#include<iostream>
#include<queue>
using namespace std;
int n, a, b;
int k[1145];
bool v[1145];
struct node {
    int fl, cnt;
};
int main() {
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
    }
    queue<node> q;
    q.push({ a,0 });
    while (!q.empty()) {
        node now = q.front();
        q.pop();
        if (now.fl == b) {
            cout << now.cnt;
            return 0;
        }
        if (now.fl - k[now.fl] >= 1 && v[now.fl - k[now.fl]] == 0) {
            q.push({ now.fl - k[now.fl], now.cnt + 1 });
            v[now.fl - k[now.fl]] = 1;
        }
        if (now.fl + k[now.fl] <= n && v[now.fl + k[now.fl]] == 0) {
            q.push({ now.fl + k[now.fl], now.cnt + 1 });
            v[now.fl + k[now.fl]] = 1;
        }
    }
    cout << "-1";
    return 0;
}