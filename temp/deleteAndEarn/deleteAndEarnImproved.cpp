//
// Created by MacBook Pro on 21.10.2024.
//

#include <vector>

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if (nums.empty()) return 0;

        // Step 1: Count frequencies
        vector<int> frequencies(10001, 0);  // 0 to 10000
        for (int num : nums) {
            frequencies[num]++;
        }

        // Step 2: DP with space optimization
        int prev2 = 0, prev1 = frequencies[1] * 1;
        for (int i = 2; i < frequencies.size(); i++) {
            int current = max(prev1, prev2 + frequencies[i] * i);
            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }
};
