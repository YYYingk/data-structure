#include<iostream>
using namespace std;
int n, k;
int x[25];
int ans;

bool isp(int y) {
    if (y == 1) return 0;
    for (int i = 2; i * i <= y; i++) {
        if (y % i == 0) return 0;
    }
    return 1;
}
void dfs(int now, int sum, int z) {
    if (now == k) {
        if (isp(sum))ans++;
        return;
    }
    for (int i = z; i <= n - k + now + 1; i++) {
        dfs(now + 1, sum + x[i], i + 1);
    }
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    dfs(0, 0, 1);
    cout << ans << endl;
    return 0;
}

// 此题与下方的2036相似