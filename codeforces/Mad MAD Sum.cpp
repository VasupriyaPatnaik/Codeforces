#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Defining the maximum array size
const int MAX_N = 200005;

int n;                    // Number of elements in the array
int a[MAX_N];             // Array to hold the input values
bool visited[MAX_N];      // Array to track which elements have been seen during processing

// Function to process the array and update elements based on the logic provided
void process() {
    // Reset visited array for the current process
    fill(visited, visited + n + 1, false); 
    int max_value = 0; // Variable to keep track of the maximum value encountered

    // Traverse the array and modify its elements based on whether they have been encountered before
    for (int i = 1; i <= n; ++i) {
        // If the element has been seen before, update the maximum value
        if (visited[a[i]]) {
            max_value = max(max_value, a[i]);
        }
        // Mark the current element as visited
        visited[a[i]] = true;
        // Update the element to the current maximum value
        a[i] = max_value;
    }
}

// Function to solve the problem for a single test case
void solve() {
    // Input the size of the array
    cin >> n;

    // Input the elements of the array
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    ll result = 0; // Variable to store the result

    // Calculate the initial sum of all elements in the array
    for (int i = 1; i <= n; ++i) {
        result += a[i];
    }

    // Apply the process function twice to modify the array
    process(); 
    for (int i = 1; i <= n; ++i) {
        result += a[i]; // Add the modified array values to the result
    }
    process(); // Apply process again

    // Add the weighted sum of the elements based on their positions in the array
    for (int i = 1; i <= n; ++i) {
        result += (n - i + 1) * 1LL * a[i]; // Multiply each element by a factor based on its position
    }

    // Output the final result for this test case
    cout << result << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);  // Disable synchronization between C++ streams and C streams for faster I/O
    cin.tie(0);                        // Untie cin from cout for even faster I/O

    int test_cases = 1;  // Default to 1 test case
    cin >> test_cases;   // Input the number of test cases

    // Process each test case
    while (test_cases--) {
        solve(); // Call the solve function for each test case
    }

    return 0;
}
