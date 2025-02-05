#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n;
    cin >> n;
    
    vector<long long> a;
    
    // Iterate through bit positions from 62 down to 0
    for (int i = 62; i >= 0; i--) {
        long long x = 1LL << i;  // Compute 2^i
        
        // If the current bit is set in n and x is not equal to n
        if ((n & x) == x && x != n) {
            a.push_back(n - x);
        }
    }
    
    a.push_back(n);  // Add n to the list
    
    // Print the result
    cout << a.size() << "\n";
    for (long long num : a) {
        cout << num << " ";
    }
    cout << "\n";
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
