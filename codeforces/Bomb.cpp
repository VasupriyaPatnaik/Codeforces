#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;  // Read the number of test cases

    while (t--) {  // Loop over each test case
        int n, k;
        cin >> n >> k;  // Read the size of the arrays 'a' and 'b', and the required 'k'

        vector<int> a(n), b(n);
        // Read arrays a and b
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        int ok = 0, ng = 1e9+1;  // Initializing search range for binary search (ok = lower bound, ng = upper bound)
        
        while (ng - ok > 1) {  // Binary search to find the optimal "mid"
            int mid = (ok + ng) / 2;  // Midpoint between ok and ng

            long long sum = 0;
            // Calculate how many elements we can get by subtracting mid from each a[i]
            // and dividing by b[i], adding 1 to make it inclusive
            for (int i = 0; i < n; i++) {
                if (a[i] >= mid)
                    sum += (a[i] - mid) / b[i] + 1;  // The number of elements we can get from a[i]
            }

            if (sum >= k) ok = mid;  // If the sum is enough, we update the lower bound
            else ng = mid;  // Otherwise, we reduce the upper bound
        }

        long long ans = 0;
        int s = 0;

        // Now, calculate the total sum based on the value found for "ok"
        for (int i = 0; i < n; i++) {
            if (a[i] >= ok) {
                int m = (a[i] - ok) / b[i] + 1;  // Number of elements that can be formed from a[i] with value >= ok
                // Sum the result of all these m elements (arithmetic progression sum formula)
                ans += 1LL * m * a[i] - 1LL * m * (m - 1) / 2 * b[i];
                s += m;  // Increment total count of such elements
            }
        }

        // Subtract the excess sum to adjust for the required k elements
        ans -= 1LL * ok * (s - k);

        cout << ans << "\n";  // Output the result
    }

    return 0;
}
