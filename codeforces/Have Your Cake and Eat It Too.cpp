#include <bits/stdc++.h> 
using namespace std;

#define fastio ios::sync_with_stdio(0); cin.tie(0)

int main() {
    fastio;
    long long t, n, i, tar, p, x, a1, a2, b1, b2, c1, c2;
    cin >> t;  // Read the number of test cases

    while (t--) {
        cin >> n;  // Read the size of the arrays
        
        // Arrays to store prefix sums
        vector<long long> a(n), b(n), c(n);
        
        // Read and compute prefix sums for array A
        for (i = 0; i < n; i++) {
            cin >> x;
            if (i == 0)
                a[i] = x;  // First element is directly stored
            else
                a[i] = a[i - 1] + x;  // Prefix sum computation
        }
        
        // Read and compute prefix sums for array B
        for (i = 0; i < n; i++) {
            cin >> x;
            if (i == 0)
                b[i] = x;
            else
                b[i] = b[i - 1] + x;
        }
        
        // Read and compute prefix sums for array C
        for (i = 0; i < n; i++) {
            cin >> x;
            if (i == 0)
                c[i] = x;
            else
                c[i] = c[i - 1] + x;
        }
        
        // Calculate target sum (1/3 of total sum)
        if (a[n - 1] % 3 == 0)
            tar = a[n - 1] / 3;
        else
            tar = (a[n - 1] / 3) + 1;  // If not divisible, round up
        
        p = 0; // Flag to check if a valid partition is found
        vector<long long>::iterator it1, it2;
        
        // Find first partition in A
        it1 = lower_bound(a.begin(), a.end(), tar);
        if (it1 != a.end()) {
            a1 = 1;
            a2 = it1 - a.begin() + 1;
            
            // Find second partition in B
            it2 = lower_bound(b.begin() + a2, b.end(), b[a2 - 1] + tar);
            if (it2 != b.end()) {
                b1 = a2 + 1;
                b2 = it2 - b.begin() + 1;
                
                // Find third partition in C
                it1 = lower_bound(c.begin() + b2, c.end(), c[b2 - 1] + tar);
                if (it1 != c.end()) {
                    c1 = b2 + 1;
                    c2 = n;
                    p = 1;
                    cout << a1 << " " << a2 << " " << b1 << " " << b2 << " " << c1 << " " << c2 << "\n";
                }
            }
        }
        if (p == 1) continue;  // Skip further checking if already found
        
        // Repeat the process by starting with B
        it1 = lower_bound(b.begin(), b.end(), tar);
        if (it1 != b.end()) {
            b1 = 1;
            b2 = it1 - b.begin() + 1;
            
            it2 = lower_bound(a.begin() + b2, a.end(), a[b2 - 1] + tar);
            if (it2 != a.end()) {
                a1 = b2 + 1;
                a2 = it2 - a.begin() + 1;
                
                it1 = lower_bound(c.begin() + a2, c.end(), c[a2 - 1] + tar);
                if (it1 != c.end()) {
                    c1 = a2 + 1;
                    c2 = n;
                    p = 1;
                    cout << a1 << " " << a2 << " " << b1 << " " << b2 << " " << c1 << " " << c2 << "\n";
                }
            }
        }
        if (p == 1) continue;
        
        // Repeat the process by starting with C
        it1 = lower_bound(c.begin(), c.end(), tar);
        if (it1 != c.end()) {
            c1 = 1;
            c2 = it1 - c.begin() + 1;
            
            it2 = lower_bound(a.begin() + c2, a.end(), a[c2 - 1] + tar);
            if (it2 != a.end()) {
                a1 = c2 + 1;
                a2 = it2 - a.begin() + 1;
                
                it1 = lower_bound(b.begin() + a2, b.end(), b[a2 - 1] + tar);
                if (it1 != b.end()) {
                    b1 = a2 + 1;
                    b2 = n;
                    p = 1;
                    cout << a1 << " " << a2 << " " << b1 << " " << b2 << " " << c1 << " " << c2 << "\n";
                }
            }
        }
        
        // If no valid partition was found, print -1
        if (p == 0)
            cout << "-1\n";
    }
    return 0;
}
