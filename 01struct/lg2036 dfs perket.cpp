#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
#define INF 1E9
int n;
int s[15], b[15];
int minn = INF;

void dfs(int now, int s1, int b1) {
    if (now > n) {
        // p都没加，题目要求至少一种，故返回
        if (s1 == 1 && b1 == 0) return;
        minn = min(minn, abs(s1 - b1));
        return;
    }
    dfs(now + 1, s1 * s[now], b1 + b[now]);   // 加
    dfs(now + 1, s1, b1);             // 不加
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &s[i], &b[i]);
    }
    dfs(1, 1, 0);
    cout << minn;
    return 0;
}