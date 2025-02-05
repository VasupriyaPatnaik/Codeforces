#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)  // A macro for looping from 0 to n-1

using namespace std;

struct query {
    int i, j;  // Structure to store the indices i and j for each query
};

int main() {
    cin.tie(0);  // Disable synchronization of cin and cout for faster input/output
    ios::sync_with_stdio(false);  // Disable synchronization with C I/O to speed up I/O operations

    int n, m;  // n is the size of the array, m is the number of queries
    cin >> n >> m;  // Read n and m from input
    vector<int> a(n);  // Array to store the elements
    forn(i, n) cin >> a[i];  // Read the array elements

    vector<vector<query>> q(n + 1);  // A vector of vectors to store queries for each possible value of x
    forn(j, m) {
        int i, x;  // i is the index, x is the query value
        cin >> i >> x;  // Read the query
        --i;  // Decrease i by 1 for 0-based indexing
        q[x].push_back({i, j});  // Store the query in the corresponding position
    }

    // Sort the queries for each value of x by the index i in descending order
    forn(i, n + 1) {
        sort(q[i].begin(), q[i].end(), [](const query &a, const query &b) {
            return a.i > b.i;  // Sort queries by i in descending order
        });
    }

    int P = min(1000, n + 1);  // Set the upper limit for P to avoid excessive computation time
    
    vector<char> ans(m);  // Vector to store the answers (YES or NO) for each query

    // Process queries for small values of k (1 <= k < P)
    for (int k = 1; k < P; ++k) {
        int cur = 1;  // Current value to check against the array elements
        int cnt = 0;  // Counter to track the number of elements processed

        // Loop over the array elements to simulate the process
        forn(i, n) {
            bool fl = false;  // Flag to indicate if the current value meets the condition
            if (a[i] >= cur) {
                ++cnt;  // Increment the count if the condition is satisfied
                fl = true;
                if (cnt == k) {  // If count reaches k, reset cur and cnt
                    ++cur;
                    cnt = 0;
                }
            }

            // Process queries that match the current index i
            while (!q[k].empty() && q[k].back().i == i) {
                ans[q[k].back().j] = fl;  // Set the answer for the current query
                q[k].pop_back();  // Remove the processed query
            }
        }
    }

    vector<int> sum1(n), sum2(n);  // Arrays to keep track of additional information
    int p2 = ceil(sqrt(n + 2));  // Calculate the square root of n for optimization

    // Lambda function to handle the addition of an element to the cost tracking
    auto add = [&](int i) {
        int bl = i / p2;  // Calculate the block number
        for (int j = bl + 1; j * p2 < n; ++j)
            ++sum1[j];  // Update sum1 for elements in the next blocks
        for (int j = i; j < (bl + 1) * p2 && j < n; ++j)
            ++sum2[j];  // Update sum2 for elements in the current block
    };

    int mx = n / P + 5;  // Set a maximum value for mx
    vector<vector<int>> pos(mx);  // Store positions of elements based on their values

    // Loop through the array and populate the pos array
    forn(i, n) {
        if (a[i] < mx)
            pos[a[i]].push_back(i);  // Store index if the element value is less than mx
        else
            add(i);  // Use the add function for larger elements
    }

    // Reverse the position lists for each value in pos
    for (auto &it : pos) reverse(it.begin(), it.end());

    // Process queries for larger values of k (k >= P)
    for (int k = P; k <= n; ++k) {
        while (true) {
            int mn = n;  // Initialize mn to the maximum possible index
            int who = -1;  // Variable to store the value that satisfies the condition

            // Loop through all levels in pos to find the best candidate
            forn(lvl, mx) if (!pos[lvl].empty()) {
                int i = pos[lvl].back();  // Get the current index for this level
                if (mn < i) continue;  // Skip if the current index is larger than the minimum

                int cnt = sum1[i / p2] + sum2[i];  // Calculate the count of elements satisfying the condition
                if (a[i] >= cnt / k + 1) {  // If the condition is met, update the minimum index
                    mn = i;
                    who = lvl;
                }
            }

            if (who == -1) break;  // Exit the loop if no suitable index is found
            add(mn);  // Call the add function for the selected index
            pos[who].pop_back();  // Remove the selected index from pos
        }

        // Process queries for the current value of k
        for (auto it : q[k]) {
            int lvl = a[it.i];  // Get the level for the current query
            ans[it.j] = (lvl >= mx || pos[lvl].empty() || pos[lvl].back() > it.i);  // Set the answer based on conditions
        }
    }

    // Output the results for all queries
    for (auto x : ans) cout << (x ? "YES" : "NO") << '\n';
    return 0;
}
