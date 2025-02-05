#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()

const char nl = '\n';
typedef long long ll;
typedef long double ld;

using namespace std;

void solve() {
    int n;
    cin >> n;  // Number of flowers
    
    vector<int> h(n);
    for (auto &x: h) cin >> x;  // Read heights of flowers
    
    int ans = h[n - 1];  // The last flower will take at least h[n - 1] seconds
    for (int i = n - 2; i >= 0; i--) {
        // For each flower, it will take max(ans + 1, h[i]) seconds to reach zero
        ans = max(ans + 1, h[i]);
    }

    cout << ans << nl;  // Output the time it takes for all flowers to become zero
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);  // Speed up I/O
    
    int T;
    cin >> T;  // Number of test cases
    while (T--) solve();  // Solve each test case
}
