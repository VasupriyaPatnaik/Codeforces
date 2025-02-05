#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;  // Read the number of test cases
    while (t--) {
        int n;
        cin >> n;  // Read the size of the grid for each test case
        vector<string> s(2);  // Create a vector to store the two strings representing the grid
        for (auto& x : s) cin >> x;  // Read the two strings representing the grid
        
        int ans = 0;  // Initialize the answer to store the count of valid configurations
        
        // Iterate through each position of the second row (excluding the first and last positions)
        for (int i = 1; i < n - 1; ++i) {
            bool ok = true;  // Initialize a flag to check if the conditions are satisfied
            
            // Condition 1: Both rows must have '.' at the current position
            ok &= (s[0][i] == '.' && s[1][i] == '.');
            
            // Condition 2: The element at the same position in the previous row must be different
            ok &= (s[0][i - 1] != s[1][i - 1]);
            
            // Condition 3: The element at the same position in the next row must be different
            ok &= (s[0][i + 1] != s[1][i + 1]);
            
            // Condition 4: The previous and next positions in the same row must be equal
            ok &= (s[0][i - 1] == s[0][i + 1]);
            
            // If all conditions are satisfied, increment the answer
            ans += ok;
        }
        
        // Output the result for this test case
        cout << ans << '\n';
    }
}
