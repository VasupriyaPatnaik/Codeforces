#include <bits/stdc++.h>
using namespace std;

// Function to count the maximum rounds Egor can win
long long max_winning_rounds(long long n, long long lower_bound, long long upper_bound, vector<long long>& cards) {
    long long sum = 0, start = 0, rounds_won = 0;
    
    // Iterate through all cards
    for (long long end = 0; end < n; end++) {
        sum += cards[end];  // Add the current card to the sum
        
        // If the sum exceeds the upper bound, remove cards from the start until it's within range
        while (sum > upper_bound) {
            sum -= cards[start];
            start++;  // Move the starting point of the current selection
        }
        
        // If the sum of selected cards is within the valid range [lower_bound, upper_bound], win the round
        if (sum >= lower_bound && sum <= upper_bound) {
            rounds_won++;  // Increment the count of rounds won
            start = end + 1;  // Move the start to the next card after the current round
            sum = 0;  // Reset sum for the next round
        }
    }
    return rounds_won;  // Return the total number of rounds won
}

int main() {
    long long t;  // Number of test cases
    cin >> t;
    
    // Process each test case
    while (t--) {
        long long n, lower_bound, upper_bound;  // Number of cards, lower and upper bounds for winning
        cin >> n >> lower_bound >> upper_bound;
        
        vector<long long> cards(n);  // Vector to store the card values
        for (long long i = 0; i < n; i++) {
            cin >> cards[i];  // Read the card values
        }
        
        // Call the function to get the result for the current test case
        long long result = max_winning_rounds(n, lower_bound, upper_bound, cards);
        
        // Output the result
        cout << result << endl;
    }
    
    return 0;  // End of program
}
