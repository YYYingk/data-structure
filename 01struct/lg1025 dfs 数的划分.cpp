#include<iostream>
using namespace std;
int k, n, ans = 0;

//void dfs(int last, int stp, int sum) {
//    if (stp > k) {
//        if (sum == n) ans++;
//        return;
//    }
//    for (int i = last; i <= n - k + 1; i++) {
//        dfs(i, stp + 1, sum + i);
//    }
//}
//int main() {
//    cin >> n >> k;
//    dfs(1, 1, 0);
//    cout << ans;
//    return 0;
//}

#include<iostream>
using namespace std;
int k, n, ans = 0;

void dfs(int last, int stp, int sum) {
    if (stp > k) {
        if (sum == n) ans++;
        return;
    }
    for (int i = last; i <= n - k + 1; i++) {
        if (sum + i * (k - stp + 1) > n)break;
        dfs(i, stp + 1, sum + i);
    }
}
int main() {
    cin >> n >> k;
    dfs(1, 1, 0);
    cout << ans;
    return 0;
}