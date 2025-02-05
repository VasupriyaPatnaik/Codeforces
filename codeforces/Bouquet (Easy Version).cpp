#include<bits/stdc++.h>
#define ll long long
using namespace std;

int a[200001];  // Array to store the input values

int main(){
    int t;
    cin >> t;  // Read the number of test cases

    while(t--) {  // Loop over each test case
        ll n, m;
        cin >> n >> m;  // Read the number of elements 'n' and the maximum allowed sum 'm'

        // Read the elements into the array 'a'
        for(int i = 1; i <= n; i++) cin >> a[i];

        sort(a + 1, a + n + 1);  // Sort the array in ascending order

        ll ans = 0, i = 0, j = 0, x = 0;  // Initialize variables for answer, two pointers i and j, and the current sum 'x'

        // Sliding window technique to find the maximum sum
        while(i <= n) {
            i++;  // Increment i to expand the window
            x += a[i];  // Add a[i] to the current sum 'x'
            
            // Shrink the window by incrementing j if the sum exceeds 'm' or the difference between a[i] and a[j] is greater than 1
            while(x > m || a[i] - a[j] > 1) {
                x -= a[j];  // Subtract a[j] from the sum
                j++;  // Move the left pointer to the right
            }

            // Update the answer with the maximum value of x (the sum within the valid window)
            ans = max(ans, x);
        }

        cout << ans << endl;  // Output the result for the current test case
    }

    return 0;
}
