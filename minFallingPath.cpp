//
// Created by MacBook Pro on 18.11.2024.
//

#include <vector>

using namespace std;


class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int size = matrix.size();


        vector<vector<int>> dp(size, vector<int>(size, 0));

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {

                //for the first row
                if(i == 0) {
                    dp[i][j] = matrix[i][j];
                }
                //for the first columns
                else if(i != 0 && j == 0) {
                    dp[i][j] = matrix[i][j] + min(dp[i-1][j], dp[i-1][j+1]);
                }
                //for the last columns
                else if(i != 0 && j == size - 1) {
                    dp[i][j] = matrix[i][j] + min(dp[i-1][j], dp[i-1][j-1]);
                }
                else {
                    dp[i][j] = matrix[i][j] + min(dp[i-1][j+1],min(dp[i-1][j], dp[i-1][j-1]));
                }

            }
        }

        int min = dp[size-1][size-1];
        for(int i = 0; i < size; i++) {
            if(dp[size-1][i] < min) {
                min = dp[size-1][i];
            }

        }

        return min;

    }
};