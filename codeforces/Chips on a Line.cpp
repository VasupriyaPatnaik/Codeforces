#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

// Function to add two numbers under modulo MOD
int add(int x, int y) {
    x += y;
    while (x >= MOD) x -= MOD;  // Keep x within the bounds of MOD
    while (x < 0) x += MOD;     // Ensure x is non-negative
    return x;
}

// Function to multiply two numbers under modulo MOD
int mul(int x, int y) {
    return (x * 1ll * y) % MOD;  // Multiply and take modulo
}

int main() {
    int n, x, m;
    cin >> n >> x >> m;  // Read the values of n (number of elements), x (index for Fibonacci), and m (target cost)

    // Precompute the first 30 Fibonacci numbers and store them in 'fib'
    vector<int> fib = {0, 1};
    for (int i = 2; i <= 30; i++) 
        fib.push_back(fib[i - 1] + fib[i - 2]);

    // Calculate the maximum sum possible by multiplying Fibonacci[x] with n
    int max_sum = fib[x] * n;

    // Initialize the dp array where dp[j][k] represents the number of ways to achieve a sum j with exactly k elements
    vector<vector<int>> dp(max_sum + 1, vector<int>(n + 1));
    dp[0][0] = 1;  // Base case: 1 way to have a sum of 0 with 0 elements

    // Dynamic programming to compute the number of ways to reach each possible sum using the first x Fibonacci numbers
    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < max_sum; j++) {
            for (int k = 0; k < n; k++) {
                if (j + fib[i] <= max_sum)  // Ensure we do not exceed max_sum
                    dp[j + fib[i]][k + 1] = add(dp[j + fib[i]][k + 1], dp[j][k]);  // Update dp value
            }
        }
    }

    // Array to store the minimum number of Fibonacci numbers required to form a sum
    vector<int> cost(max_sum + 1, 1e9);
    cost[0] = 0;  // No cost to form a sum of 0

    // Dynamic programming to compute the minimum number of Fibonacci numbers required to form each possible sum
    for (int j = 1; j <= max_sum; j++) {
        for (int i = 1; i <= 30; i++) {
            if (j >= fib[i])  // If the current sum j is large enough to subtract fib[i]
                cost[j] = min(cost[j], cost[j - fib[i]] + 1);  // Update cost[j] with the minimum number of Fibonacci numbers
        }
    }

    // Calculate the final answer by summing the dp values where the cost is equal to m
    int ans = 0;
    for (int i = 0; i <= max_sum; i++) {
        if (cost[i] == m)  // Only consider sums that can be formed with exactly m Fibonacci numbers
            ans = add(ans, dp[i][n]);  // Add the number of ways to form sum i with n elements
    }

    cout << ans << endl;  // Output the result
}
