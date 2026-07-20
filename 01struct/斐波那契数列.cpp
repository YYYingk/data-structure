#include<iostream>
using namespace std;
int n;
int v[11451419];

int fb(int x) {
	if (x <= 0) return 0;
	if (x == 1 || x == 2) return 1;
	if (v[x]) return v[x];
	else {
		v[x] = fb(x - 1) + fb(x - 2);
		return v[x];
	}
}

int main() {
	cin >> n;
	int ans = fb(n);
	cout << ans;
	return 0;
}