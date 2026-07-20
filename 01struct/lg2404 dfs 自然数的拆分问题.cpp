#include<iostream>
using namespace std;
int n;
int a[11];

void dfs(int sum, int z, int t) {
    if (sum == n) {
        for (int i = 1; i <= z - 2; i++) {
            cout << a[i] << '+';
        }
        cout << a[z - 1] << endl;
        return;
    }
    if (sum > n) return;
    for (int i = t; i <= n - 1; i++) {
        a[z] = i;
        dfs(sum + i, z + 1, i);
        // a[z] = 0;
    }
}
int main() {
    cin >> n;
    dfs(0, 1, 1);
    return 0;
}