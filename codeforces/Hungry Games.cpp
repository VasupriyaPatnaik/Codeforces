#include <bits/stdc++.h>  // Includes all standard C++ libraries
using namespace std;

using ll = long long;  // Define a shorthand for long long

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);  // Fast I/O optimization

    int tests;
    cin >> tests;  // Read the number of test cases
    
    while (tests--) {
        int n;
        ll x;
        cin >> n >> x;  // Read `n` (size of array) and `x` (given value)
        
        vector<ll> a(n + 1);  // Array to store prefix sums (1-based indexing)
        for (int i = 1; i <= n; ++i) cin >> a[i];  // Read array elements
        
        // Compute prefix sum of the array
        partial_sum(a.begin() + 1, a.end(), a.begin() + 1);
        
        vector<int> dp(n + 2, 0);  // DP array to store results
        
        // Process the array in reverse order
        for (int i = n - 1; i >= 0; --i) {
            // Find the first position `q` where a[q] > a[i] + x using upper_bound
            int q = upper_bound(a.begin(), a.end(), a[i] + x) - a.begin();
            
            // Compute dp[i] based on dp[q] and distance (q - i - 1)
            dp[i] = dp[q] + q - i - 1;
        }

        // Sum up all dp values to get the final answer
        cout << accumulate(dp.begin(), dp.end(), 0ll) << '\n';
    }

    return 0;
}
