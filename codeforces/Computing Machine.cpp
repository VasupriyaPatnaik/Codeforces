#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    string a, b;
    cin >> a >> b;

    // Precompute whether each index in 'a' can be '1'
    vector<bool> canBeOne(n, false);
    for (int i = 0; i < n; ++i) {
        if (a[i] == '1') {
            canBeOne[i] = true;
        }
    }

    // Check for indices 1 and n-2 separately
    if (n > 1) {
        if (!canBeOne[1] && b[0] == '1' && b[2] == '1') {
            canBeOne[1] = true;
        }
        if (n > 2 && !canBeOne[n - 2] && b[n - 3] == '1' && b[n - 1] == '1') {
            canBeOne[n - 2] = true;
        }
    }

    // Check for indices 2 to n-3
    for (int i = 2; i < n - 2; ++i) {
        if (!canBeOne[i]) {
            if ((b[i - 1] == '1' || a[i - 2] == '0') && (b[i + 1] == '1' || a[i + 2] == '0')) {
                canBeOne[i] = true;
            }
        }
    }

    // Compute prefix sums for canBeOne
    vector<int> prefixSum(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefixSum[i + 1] = prefixSum[i] + (canBeOne[i] ? 1 : 0);
    }

    int q;
    cin >> q;

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--; // Convert to 0-based indexing
        r--;

        int ans = 0;

        // Count initial '1's at the boundaries
        if (a[l] == '1') ans++;
        if (l < r && a[r] == '1') ans++;

        // Check for l+1 and r-1
        if (l + 1 < r) {
            if (a[l + 1] == '1' || (b[l] == '1' && (b[l + 2] == '1' || (l + 2 < r && a[l + 3] == '0')))) {
                ans++;
            }
        }
        if (r - 1 > l + 1) {
            if (a[r - 1] == '1' || (b[r] == '1' && (b[r - 2] == '1' || a[r - 3] == '0'))) {
                ans++;
            }
        }

        // Add the count of '1's in the middle range
        if (r - l >= 4) {
            ans += prefixSum[r - 1] - prefixSum[l + 2];
        }

        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}