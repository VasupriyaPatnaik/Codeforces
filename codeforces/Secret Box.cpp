#include <iostream>
using namespace std;
using ll = long long;  // Defining 'll' as an alias for 'long long' for easier usage

int main() {
    int t; 
    cin >> t;  // Input number of test cases
    while(t--) {  // Loop for each test case
        ll x, y, z, k; 
        cin >> x >> y >> z >> k;  // Input the values of x, y, z, and k

        ll ans = 0;  // Variable to store the maximum number of ways

        // Iterate over all possible values of 'a' and 'b' within the limits of x and y
        for(int a = 1; a <= x; a++) {   
            for(int b = 1; b <= y; b++) {
                // If k is not divisible by the product of a and b, continue to next iteration
                if(k % (a * b)) continue;
                
                // If k is divisible by a * b, calculate the corresponding value of 'c'
                ll c = k / (a * b);
                
                // If c exceeds z, skip this combination
                if(c > z) continue;

                // Calculate the number of ways this combination (a, b, c) can happen
                ll ways = (ll)(x - a + 1) * (y - b + 1) * (z - c + 1);

                // Update the answer to be the maximum of the current answer and the new ways found
                ans = max(ans, ways);
            }
        }

        // Output the result for the current test case
        cout << ans << "\n";
    }
}
