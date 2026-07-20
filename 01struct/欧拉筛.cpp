#include<iostream>
#include<cmath>
using namespace std;
int p[11451419], isPrime[11451419];
//                0为质    1为质
int sum;
int main() {
    int n;
    cin >> n;
    isPrime[1] = 1;
    for (int i = 2; i <= n; i++) { // 穷举所有数 + 标记每个质数的倍数
        if (isPrime[i] == 0) {
            sum++;
            p[sum] = i;
        }
        //把i当做每个质数的倍数，去枚举所有质数的i倍
        for (int j = 1; j <= sum; j++) {
            int x = i * p[j];
            if (x > n) break;   // 将范围外的数据跳掉
            isPrime[x] = 1;     // 标记为质数
            if (i % p[j] == 0) break; // 保证合数只被其最小质因数标记
        }
    }

    for (int i = 1; i <= sum; i++) {
        cout << p[i] << " ";
    }
    return 0;
}