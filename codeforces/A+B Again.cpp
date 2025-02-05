#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;  // Input the number of test cases
    while (t--) {
        int n;
        cin >> n;  // Input the two-digit integer n
        int sum_of_digits = (n / 10) + (n % 10);  // Sum of the tens and ones digits
        cout << sum_of_digits << endl;  // Output the result for this test case
    }
    return 0;
}


#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;  
    while (t--) {
        int n;
        cin >> n;

        // Extract first and last digit
        int last_digit = n % 10;
        int first_digit = n;
        while (first_digit >= 10) {
            first_digit /= 10;
        }

        cout << (first_digit + last_digit) << endl; 
    }
    return 0;
}
