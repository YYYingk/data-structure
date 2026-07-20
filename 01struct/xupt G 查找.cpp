#include<iostream>
using namespace std;
int n, m, q;
int a[1145141];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= m; i++) {
		cin >> q;
		int left = 1, right = n, ans = -1;
        while (left <= right)
        {
            int mid = (right - left) / 2 + left;
            if (a[mid] >= q)
            {
                if (a[mid] == q) ans = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        if (ans == -1) cout << -1 << " ";
        else cout << ans << " ";
	}
	return 0;
}