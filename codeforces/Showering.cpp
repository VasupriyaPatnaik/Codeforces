#include <iostream>
#include <vector>
#include <algorithm>

// Class to schedule showers between tasks
class ShowerScheduler {
private:
    // Structure to represent each task with start and end times
    struct Task {
        long long start, end;
        Task(long long s, long long e) : start(s), end(e) {}
    };

    long long taskCount, showerTime, dayLength;  // Task count, shower duration, and total day length
    std::vector<Task> tasks;  // Vector to store tasks

    // Check if a shower can be taken before the first task
    bool canShowerBefore(const Task& firstTask) const {
        return firstTask.start >= showerTime;  // Can shower if the first task starts after or at the required shower time
    }

    // Check if a shower can be taken between two tasks
    bool canShowerBetween(const Task& prevTask, const Task& currTask) const {
        return currTask.start - prevTask.end >= showerTime;  // Can shower if there's enough gap between tasks
    }

    // Check if a shower can be taken after the last task
    bool canShowerAfter(const Task& lastTask) const {
        return dayLength - lastTask.end >= showerTime;  // Can shower if there's enough time after the last task
    }

public:
    // Function to read input and initialize the tasks
    void readInput() {
        std::cin >> taskCount >> showerTime >> dayLength;  // Read the task count, shower time, and day length
        tasks.reserve(taskCount);  // Reserve memory for the tasks vector

        // Reading the start and end times of each task
        for (long long i = 0; i < taskCount; ++i) {
            long long start, end;
            std::cin >> start >> end;  // Read start and end times
            tasks.emplace_back(start, end);  // Add the task to the vector
        }

        // Sort tasks by their start time to process them in order
        std::sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
            return a.start < b.start;
        });
    }

    // Function to check if showering is possible based on the tasks and time constraints
    bool isShoweringPossible() const {
        // If there are no tasks or we can shower before the first task
        if (tasks.empty() || canShowerBefore(tasks[0])) {
            return true;  // It's possible to shower
        }

        // Iterate through tasks and check if showering is possible between any two tasks
        for (size_t i = 1; i < tasks.size(); ++i) {
            if (canShowerBetween(tasks[i-1], tasks[i])) {
                return true;  // Showering is possible between these two tasks
            }
        }

        // Check if showering is possible after the last task
        return canShowerAfter(tasks.back());
    }
};

int main() {
    // Fast input-output to handle large inputs efficiently
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int testCases;  // Variable to store the number of test cases
    std::cin >> testCases;  // Read number of test cases

    while (testCases--) {
        ShowerScheduler scheduler;  // Create a ShowerScheduler object
        scheduler.readInput();  // Read input for this test case
        std::cout << (scheduler.isShoweringPossible() ? "YES" : "NO") << std::endl;  // Output the result (YES or NO)
    }

    return 0;
}
