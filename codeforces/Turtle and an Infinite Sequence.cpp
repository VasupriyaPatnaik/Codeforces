#include <iostream>

using namespace std;

int main()
{
    int t; // Number of test cases
    cin >> t; // Input number of test cases
    
    // Loop through each test case
    while (t--) {
        int n, m; // n is the index, m is the number of seconds
        cin >> n >> m; // Input values of n and m
        
        // Initialize ans to n, and then perform bitwise OR operations
        // with max(0, n - m) and (n + m)
        int ans = n | max(0, n - m) | (n + m);
        
        // Perform a bitwise OR for values i which are powers of 2, up to m
        // This simulates the changes in the sequence after m seconds
        for (int i = 1; i <= m; i *= 2) {
            ans |= i; // OR with the current power of 2
        }
        
        // Output the result for the current test case
        cout << ans << '\n';
    }
}
