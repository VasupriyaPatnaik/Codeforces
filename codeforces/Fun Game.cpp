#include <bits/stdc++.h>  // Includes all standard C++ libraries
using namespace std;

// Function to solve a single test case
void solve() {
    int n; 
    cin >> n;  // Read the length of the strings
    
    string s, t;
    cin >> s >> t;  // Read the two strings s and t
    
    // Iterate through the string s and check leading '0's
    for (int i = 0; i < s.size() && s[i] == '0'; ++i) {
        // If the corresponding character in t is not '0', print "NO" and return
        if (t[i] != '0') {
            cout << "NO\n";
            return;
        }
    }
    
    // If all leading '0's in s have corresponding '0's in t, print "YES"
    cout << "YES\n";
}

int main() {
    int t; 
    cin >> t;  // Read the number of test cases
    
    while (t--) solve();  // Run solve() for each test case
    
    return 0;
}
