#include <bits/stdc++.h>
 
using namespace std;

// Define a large value INF (1 billion), which is used as an upper bound in some operations
const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);  // Speed up input and output operations
    int t;
    cin >> t;  // Read the number of test cases
    while (t--) {  // Process each test case
        int n;
        cin >> n;  // Read the number of vertices (nodes) in the tree
        vector<int> a(n);  // Vector to store the values at each vertex
        for (auto& x : a) cin >> x;  // Read the values for each vertex

        vector<vector<int>> g(n);  // Graph to represent the tree structure (adjacency list)
        
        // Read the parent-child relationships to form the tree
        for (int i = 1; i < n; ++i) {
            int p;
            cin >> p;  // Read the parent of vertex i+1
            g[p - 1].push_back(i);  // Add the child vertex i to the adjacency list of parent vertex p-1
        }
        
        // Lambda function 'check' used for checking if a specific value of x is valid
        // This function is called recursively to traverse the tree and check if the condition holds
        auto check = [&](auto&& self, int v, int x) -> bool {
            if (x > INF) return false;  // If x exceeds INF, the condition fails

            bool isLeaf = true;  // Flag to check if the current vertex is a leaf (no children)

            // Update the value of x at vertex v, ensuring it's not negative
            if (v) x += max(0, x - a[v]);

            // Recursively check the subtrees (children) of the current vertex v
            for (auto u : g[v]) {
                isLeaf = false;  // Current vertex is not a leaf
                if (!self(self, u, x)) return false;  // If any child fails the condition, return false
            }

            // If the vertex is a leaf, check if x is less than or equal to a[v]
            return (!isLeaf || x <= a[v]);
        };

        // Binary search to find the maximum possible value of x
        int l = 1, r = INF;
        while (l <= r) {
            int mid = (l + r) / 2;  // Calculate the midpoint

            // If the check function returns true for 'mid', we can try higher values of x
            if (check(check, 0, mid)) {
                l = mid + 1;  // Move the lower bound to mid + 1
            } else {
                r = mid - 1;  // Otherwise, reduce the upper bound to mid - 1
            }
        }
        
        // Output the result: the maximum possible value of x for the root
        cout << a[0] + l - 1 << '\n';
    }
}
