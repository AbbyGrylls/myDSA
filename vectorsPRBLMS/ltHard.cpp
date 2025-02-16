#include <iostream>
#include <vector>
#include <algorithm>  // For reverse()

using namespace std;

class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        int size = 2 * n - 1;
        vector<int> ans(size, 0);  // Initialize ans with zeros
        vector<int> set;

        // Step 1: Fill the `set` vector with numbers from n to 1 (each twice except 1)
        for (int i = 0; i < n; i++) {
            if (n - i != 1) {  
                set.push_back(n - i);
                set.push_back(n - i);
            } else {
                set.push_back(1);
            }
        }
           
        // Step 2: Reverse the `set` vector to start with the largest number first
       // reverse(set.begin(), set.end());

        // Step 3: Place numbers in `ans` based on conditions
        ans[0] = set[0];
        ans[n] = set[1];  // Ensuring the first large number is placed correctly

        int index = 2;
        for (int i = 1; i < size; i++) {
            if (index >= set.size()) break;  // Prevent out-of-bounds errors

            int check = set[index];
            if (check > 1) {
                // Ensure the number can be placed at both positions
                if (i + check < size && ans[i] == 0 && ans[i + check] == 0) {
                    ans[i] = check;
                    ans[i + check] = check;
                    index += 2;
                }
            } else {
                // Place `1` if it's available
                if (ans[i] == 0) {
                    ans[i] = 1;
                    index++;
                }
            }
        }
        return ans;
    }
};

// Driver code to test
int main() {
    Solution sol;
    int n = 3;
    vector<int> result = sol.constructDistancedSequence(n);

    for (int num : result) {
        cout << num << " ";
    }
    return 0;
}
