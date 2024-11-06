//
// Created by MacBook Pro on 7.11.2024.
//
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int length = triangle.size();
        int lastRowSize = triangle[length - 1].size();
        vector<vector<int>> dp(length, vector<int>(lastRowSize, 0));

        if(length == 1) {
            return triangle[0][0];
        }

        //base case: fill the bottom
        for(int i = 0; i < lastRowSize; i++) {
            dp[length - 1][i] = triangle[length - 1][i];
        }

        //fill the rest (bottom-up approach)
        for(int i = length - 2; i > -1; i--) {
            for(int j = 0; j < triangle[i].size(); j++) {
                dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];
            }
        }

        return dp[0][0];


    }
};