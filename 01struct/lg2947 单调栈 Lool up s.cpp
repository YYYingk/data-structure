#include<iostream>
#include<stack>
using namespace std;
int n, tmp;
int a[1145141];
stack<int> s;
int ans[1145141];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = n; i >= 1; i--) {
        while (!s.empty() && a[s.top()] <= a[i]) {
            s.pop();
        }
        if (s.empty()) {
            ans[i] = 0;
        }
        else {
            ans[i] = s.top();
        }
        s.push(i);
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}