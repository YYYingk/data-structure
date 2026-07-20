#include<iostream>
#include<string>
using namespace std;
typedef unsigned long long ull;
ull h1[1145], m = 19260817;
ull pb[1145];
ull h2=0;
string s1, s2;
int ans, b=131;

int main() {
	cin >> s1 >> s2;
	int n1 = s1.size();
	int n2 = s2.size();
	pb[0] = 1;
	for (int i = 0; i < n1; i++) {
		h1[i + 1] = (h1[i] * b + s1[i]) % m;
		pb[i + 1] = (pb[i] * b) % m;
	}

	for (char c : s2) {
		h2 = (h2 * b + c) % m;
	}

	for (int i = 0; i <= n1 - n2; i++) {
		// 计算区间哈希：(h[i+n2] - h[i]*B^n2) mod MOD，避免负值/无符号下溢
		ull h = (h1[i + n2] + m - (h1[i] * pb[n2]) % m) % m;
		if (h < 0) h += m;
		if (h == h2) {
			ans++;
		}
	}

	if (ans > 0) {
		cout << "s2 is s1`s subchuan" << endl;
		cout << "subnum is : " << ans << endl;
	}
	else {
		cout << "s2 is not s1 subchuan" << endl;
	}

	return 0;
}

//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//using ull = unsigned long long;

//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    string s1, s2;
//    cin >> s1 >> s2;
//
//    const ull MOD = 19260817;
//    const ull B = 131;
//
//    size_t n1 = s1.size();
//    size_t n2 = s2.size();
//
//    vector<ull> h1(n1 + 1, 0), pb(n1 + 1, 0);
//    pb[0] = 1;
//    for (size_t i = 0; i < n1; ++i) {
//        h1[i + 1] = (h1[i] * B + (unsigned char)s1[i]) % MOD;
//        pb[i + 1] = (pb[i] * B) % MOD;
//    }
//
//    ull h2 = 0;
//    for (char c : s2) {
//        h2 = (h2 * B + (unsigned char)c) % MOD;
//    }
//
//    int ans = 0;
//    for (size_t i = 0; i + n2 <= n1; ++i) {
//        // 计算区间哈希：(h[i+n2] - h[i]*B^n2) mod MOD，避免负值/无符号下溢
//        ull tmp = (h1[i + n2] + MOD - (h1[i] * pb[n2]) % MOD) % MOD;
//        if (tmp == h2) ++ans;
//    }
//
//    if (ans > 0) {
//        cout << "s2 is s1`s subchuan\n";
//        cout << "subnum is : " << ans << '\n';
//    }
//    else {
//        cout << "s2 is not s1 subchuan\n";
//    }
//    return 0;
//}