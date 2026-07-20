#include<iostream>
using namespace std;
long long a, b, p;
long long x, n, ans = 1;
int main() {
    cin >> a >> b >> p;
    x = b, n = a;
    while (x != 0) {
        if (x % 2 == 1) ans = (ans * n) % p;
        x /= 2;
        // 不停翻倍，也就是让其处于该处于的二进制位，到必要时再乘
        n = (n * n) % p;
    }
    ans = ans % p;
    cout << a << "^" << b << " mod " << p << "=" << ans;
    return 0;
}