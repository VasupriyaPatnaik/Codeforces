#include<bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(0);cin.tie(0) // Fast input/output

long long ara[200005], b[200005], d[200005]; // Arrays for sequences

int main()
{
    fastio; // Enable fast input/output
    long long t, n, m, p, i, tot, f; // t = number of test cases, n = size of arrays, m = number of elements in the update array, p = flag for checking a condition, tot = count of differences, f = another flag for checking the last condition
    cin >> t; // Read number of test cases
    while (t--) // Loop for each test case
    {
        cin >> n; // Read the size of the arrays
        tot = 0; // Initialize total count of differences
        f = 0; // Initialize flag for checking the last condition
        p = 0; // Initialize flag for checking if certain element exists
        for (i = 0; i < n; i++) // Read the first array (ara)
            cin >> ara[i];
        
        map<long long, long long> dif; // Map to store the count of differences
        
        for (i = 0; i < n; i++) // Read the second array (b) and check for differences
        {
            cin >> b[i];
            if (ara[i] != b[i]) { // If elements differ
                dif[b[i]]++; // Increase the count of the differing value in the map
                tot++; // Increase the total number of differences
            }
        }
        
        cin >> m; // Read the number of elements in the update array (d)
        
        for (i = 0; i < m; i++) // Read the update array (d)
        {
            cin >> d[i];
            if (i == m - 1 && dif[d[i]] > 0) // If this is the last element in d and it exists in the differences map
                f = 1; // Set flag to 1
        }
        
        for (i = 0; i < m; i++) // Check if any element in d exists in the differences map and reduce the count of that element
        {
            if (dif[d[i]] > 0)
            {
                dif[d[i]]--; // Decrease the count in the map
                tot--; // Decrease the total number of differences
            }
        }
        
        if (tot != 0) // If there are still differences left
        {
            cout << "NO\n"; // Output "NO"
            continue; // Continue to the next test case
        }
        
        if (f == 1) // If the last element of d was found in the differences map
        {
            cout << "YES\n"; // Output "YES"
            continue; // Continue to the next test case
        }
        
        // Check if there is an element that is the same in both ara and b, and also matches the last element in d
        for (i = 0; i < n; i++)
        {
            if (ara[i] == b[i] && ara[i] == d[m - 1]) // If ara[i] and b[i] are equal and match the last element in d
            {
                p = 1; // Set flag to 1
                break; // Break out of the loop
            }
        }
        
        if (p == 1) // If the flag was set
            cout << "YES\n"; // Output "YES"
        else
            cout << "NO\n"; // Otherwise, output "NO"
    }
    
    return 0;
}
