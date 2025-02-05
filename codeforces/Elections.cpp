#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, c;
    cin >> n >> c; // Read the number of candidates (n) and undecided voters (c)

    vector<int> a(n); // Vector to store the number of fans for each candidate
    for (int i = 0; i < n; ++i) {
        cin >> a[i]; // Read the number of fans for each candidate
    }

    // Handle the case when there is only one candidate
    if (n == 1) {
        cout << "0\n"; // No exclusions needed since there's only one candidate
        return;
    }

    // Find the maximum number of fans among candidates 2 to n (excluding candidate 1)
    int mx = *max_element(a.begin() + 1, a.end());

    // Determine the maximum votes between candidate 1 (with undecided voters added) and the other candidates
    int mxc = max(a[0] + c, mx);

    // Determine the winner:
    // If candidate 1 has the maximum votes (including undecided voters), they are the winner.
    // Otherwise, the winner is the candidate with the maximum fans among candidates 2 to n.
    int winner = mxc == a[0] + c ? 0 : find(a.begin() + 1, a.end(), mx) - a.begin();

    // Initialize a running sum of undecided voters and fans
    ll sum = c; // Start with the undecided voters

    // For each candidate, calculate the minimum number of exclusions needed for them to win
    for (int i = 0; i < n; sum += a[i], ++i) {
        int answer;

        // If the current candidate is the winner, no exclusions are needed
        if (i == winner) {
            answer = 0;
        }
        // If the current candidate can win by excluding some candidates
        else if (sum + a[i] >= mx) {
            answer = i; // Exclude candidates up to the current one
        }
        // Otherwise, exclude all candidates up to the current one plus one more
        else {
            answer = i + 1;
        }

        // Output the result for the current candidate
        cout << answer << " \n"[i == n - 1]; // Add a newline after the last candidate
    }
}

int main() {
    ios::sync_with_stdio(false); // Disable synchronization with C-style I/O for faster input/output
    cin.tie(nullptr); // Untie cin from cout for faster input/output

    int test = 1;
    cin >> test; // Read the number of test cases
    
    // Process each test case
    while (test--) {
        solve();
    }

    return 0;
}