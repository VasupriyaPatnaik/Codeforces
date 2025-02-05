#include <bits/stdc++.h>
using namespace std;

int main(){
    // Read the number of test cases
    int t; cin >> t;
    
    // Process each test case
    while(t--){
        int h, n; 
        // Read the health of the monster (h) and the number of warriors (n)
        cin >> h >> n;
        
        // Read the attack damage array (a) and the cooldown times array (c)
        vector<int> a(n), c(n);
        for(int& i: a) cin >> i;  // Attack damage of each warrior
        for(int& i: c) cin >> i;  // Cooldown time for each warrior

        // A set to store the warriors, ordered by their available time to attack
        // Each element in the set is a pair {time_of_attack, warrior_index}
        set<pair<long long, int>> S;
        
        // Initially, all warriors are ready to attack at turn 1
        for(int i = 0; i < n; i++){
            S.insert({1, i});  // All warriors are available at turn 1
        }

        long long last_turn = 1;  // Store the last turn when an attack happens
        
        // Simulate the process of attacking until the monster's health becomes 0 or less
        while(h > 0){
            // Get the warrior who will attack next (the one with the smallest available turn)
            auto p = *S.begin();
            long long turn = p.first;
            int i = p.second;
            S.erase(S.begin());  // Remove that warrior from the set
            
            // Update the last turn at which an attack happens
            last_turn = turn;

            // Reduce the monster's health by the warrior's attack damage
            h -= a[i];

            // Add the warrior back to the set, with the new available turn
            S.insert({turn + c[i], i});
        }

        // Output the last turn at which an attack was made to reduce health to 0 or below
        cout << last_turn << "\n";
    }
}
