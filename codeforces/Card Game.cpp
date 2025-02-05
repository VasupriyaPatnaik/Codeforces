#include <cstdio>

// Function to compare two values and return:
// 1 if x > y, -1 if x < y, 0 if x == y
int compare(int x, int y) {
    return (x > y) - (x < y);
}

int main() {
    int testCases;
    scanf("%d", &testCases);

    while (testCases--) {
        int suneetCard1, suneetCard2, slavicCard1, slavicCard2;
        scanf("%d %d %d %d", &suneetCard1, &suneetCard2, &slavicCard1, &slavicCard2);

        // Calculate the result based on the comparison of card values
        int result = 2 * (compare(suneetCard1, slavicCard1) + compare(suneetCard2, slavicCard2) > 0) +
                     2 * (compare(suneetCard1, slavicCard2) + compare(suneetCard2, slavicCard1) > 0);

        // Output the result
        printf("%d\n", result);
    }

    return 0;
}