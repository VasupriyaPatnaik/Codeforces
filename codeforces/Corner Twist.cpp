#include <bits/stdc++.h>
using namespace std;
#define MP make_pair

int n, m;

// Function to read the grid and compute modular sums of rows and columns
pair<vector<int>, vector<int>> read() {
    vector<int> p(n, 0), q(m, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c; cin >> c;
            p[i] = (p[i] + (c - '0')) % 3; // Sum row-wise and take mod 3
            q[j] = (q[j] + (c - '0')) % 3; // Sum column-wise and take mod 3
        }
    }
    return MP(p, q);
}

// Function to solve each test case
void solve() {
    cin >> n >> m;
    auto first = read(); // Read first grid
    auto second = read(); // Read second grid
    cout << (first == second ? "Yes" : "No") << '\n'; // Compare results
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _; cin >> _; // Number of test cases
    while (_--) solve(); // Solve each test case
    return 0;
}
