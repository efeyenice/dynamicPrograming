//
// Created by MacBook Pro on 18.11.2024.
//



using namespace std;
#include <vector>
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (i == 0) {
                    dp[i][j] = int(matrix[i][j]- '0');
                }
                else if (j == 0) {
                    dp[i][j] = int(matrix[i][j]- '0');
                }
                else {
                    if (matrix[i][j] == '1') {
                        dp[i][j] = min(dp[i][j-1], min(dp[i - 1][j - 1], dp[i - 1][j])) + 1;
                    }
                    else {
                        dp[i][j] = 0;
                    }
                }
            }
        }
        int maxSide = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                maxSide = max(maxSide, dp[i][j]);
            }
        }


    return maxSide * maxSide;
    }
};