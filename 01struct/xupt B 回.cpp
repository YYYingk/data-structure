#include<iostream>
#include<vector>
using namespace std;
int row, col;
int map[114][114];
vector<int> v;
int main() {
	cin >> row >> col;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> map[i][j];
		}
	}

	int l = 0;                      //左边界
	int r = col - 1;   //右边界
	int u = 0;                      //上边界
	int d = row - 1;      //下边界

	while (1) {
		for (int i = l; i <= r; i++) {
			v.push_back(map[u][i]);
		}
		if (++u > d) break;
		for (int i = u; i <= d; i++) {
			v.push_back(map[i][r]);
		}
		if (--r < l) break;
		for (int i = r; i >= l; i--) {
			v.push_back(map[d][i]);
		}
		if (--d < u) break;
		for (int i = d; i >= u; i--) {
			v.push_back(map[i][l]);
		}
		if (++l > r) break;
	}
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
	return 0;
}