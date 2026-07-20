#include<iostream>
#include<algorithm>
using namespace std;
int s[10];
int sum, minn;
int left, right;
int a[114][114];

void dfs(int x, int y) {
    if (y > s[x]) {
        ::minn = min(::minn, max(::left, ::right));
        return;
    }
    ::left += a[x][y];
    dfs(x, y + 1);
    ::left -= a[x][y];
    ::right += a[x][y];
    dfs(x, y + 1);
    ::right -= a[x][y];
}

int main() {
    for (int i = 1; i <= 4; i++) {
        cin >> s[i];
    }
    for (int i = 1; i <= 4; i++) {
        minn = 19260817;
        for (int j = 1; j <= s[i]; j++) {
            cin >> a[i][j];
        }
        dfs(i, 1);
        sum += minn;
    }
    cout << sum;
    return 0;
}