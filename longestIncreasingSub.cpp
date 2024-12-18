//
// Created by MacBook Pro on 18.12.2024.
//

#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int maxLen = 1;
        vector<int> dp(nums.size(), 1);

        for(int i = 0; i < nums.size(); i++){
          bool check = true;
          for(int j = 0; j < i; j++){
            if(nums[j] < nums[i]) {
              dp[i] = max(dp[i], dp[j] + 1);
              if(dp[i] > maxLen) {maxLen = dp[i];}
            }
          }

        }
        return maxLen;
    }
};
