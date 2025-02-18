#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int cnt = n / 4;
        cout << cnt + (n - cnt * 4) / 2 << '\n';
    }

    return 0;
}
