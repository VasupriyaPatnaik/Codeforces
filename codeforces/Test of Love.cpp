#include <bits/stdc++.h>
using namespace std;

int main() {
    // Reading the number of test cases
    int t;
    cin >> t;
    
    // Loop through each test case
    while (t--) {
        // Read the values for n (length of string), m (max number of steps you can take), and k (initial value of energy)
        int n, m, k;
        cin >> n >> m >> k;
        
        // Read the string s which contains the terrain type
        string s;
        cin >> s;
        
        // Initialize dp array to store maximum energy at each position (n+2 to handle boundary conditions)
        // We use n+2 because we have to check dp[n+1] in the loop, and dp[0] will hold the initial energy 'k'
        vector<int> dp(n + 2, -1);
        
        // Set the initial energy at position 0 to k
        dp[0] = k;
        
        // Loop through each position (from 1 to n+1)
        for (int i = 1; i <= n + 1; i++) {
            
            // If the current position is not the last position (n+1) and is a 'C' (Cliff), skip this position
            if (i != n + 1 && s[i - 1] == 'C') 
                continue;
            
            // For each possible step size (from 1 to m)
            for (int t = 1; t <= m; t++)
                // If the step size is valid (i.e., within bounds and the previous position is either 0 or 'L')
                if (i - t >= 0 && (i - t == 0 || s[i - t - 1] == 'L'))
                    // Update dp[i] by taking the maximum energy value achievable by coming from dp[i-t]
                    dp[i] = max(dp[i], dp[i - t]);
            
            // If the previous position is a 'W' (Water), reduce energy by 1 at current position
            if (i > 1 && s[i - 2] == 'W') 
                dp[i] = max(dp[i], dp[i - 1] - 1);
        }
        
        // After processing all steps, check if we can reach the last position (n+1) with energy >= 0
        if (dp[n + 1] >= 0) 
            cout << "YES\n";  // If we can reach, print "YES"
        else 
            cout << "NO\n";   // Otherwise, print "NO"
    }
}
