#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false); // Disable synchronization between C and C++ standard streams for faster input/output
  cin.tie(nullptr); // Untie cin from cout to speed up input/output
  
  int t; // Declare an integer for the number of test cases
  cin >> t; // Input the number of test cases
  
  // Loop through all the test cases
  while(t > 0){
    t--; // Decrement the test case counter
    
    int n, x, y; // Declare integers for the size of the array and two indices
    cin >> n >> x >> y; // Input the values for n, x, and y
    x--; y--; // Convert to zero-based indexing (as input uses one-based indexing)
    
    vector<int> a(n, 1); // Initialize a vector of size n with all elements set to 1
    int e; // Variable to alternate between 1 and -1
    
    e = -1; // Start with -1 to alternate
    // Fill the elements from index x+1 to n-1 with alternating 1 and -1
    for(int i = x + 1; i < n; i++){
      a[i] = e; // Set the value at index i
      e *= -1; // Alternate the value of e between 1 and -1
    }
    
    e = -1; // Reset e to -1 for the next part
    // Fill the elements from index y-1 to 0 with alternating 1 and -1
    for(int i = y - 1; i >= 0; i--){
      a[i] = e; // Set the value at index i
      e *= -1; // Alternate the value of e between 1 and -1
    }
    
    // Output the final array for the current test case
    for(int i = 0; i < n; i++){
      if(i) cout << " "; // Print a space between elements, except for the first element
      cout << a[i]; // Output the value at index i
    }
    cout << "\n"; // Print a newline after each test case output
  }
  return 0; // Return 0 to indicate the program ran successfully
}
