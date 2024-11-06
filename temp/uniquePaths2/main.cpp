#include <vector>
#include <algorithm>
using namespace std;

/*we can solve this problem again with pure math
 *find all paths to bottom-right corner => a
 *find all paths from origin to the obstacle => b
 *find all paths from the obstacle to the bottom-right corner => c
 *Answer = a - (b x c)
 */

/*or use the other math method you learned
 *summing possible paths methods
 */

class Solution {
 public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
  int rows = obstacleGrid.size();
  int cols = obstacleGrid[0].size();
  vector<vector<int>> dp(rows, vector<int>(cols, 0));
  if (obstacleGrid[0][0] == 1) {
   return 0;
  }
  for (int i = 0; i < rows; i++) {
   for (int j = 0; j < cols; j++) {
    if(i == 0 && j == 0) {
     dp[i][j] = 1;
    }
    else if(obstacleGrid[i][j] == 1) {
      dp[i][j] = 0;
    }
    else if(i == 0 && j > 0) {
     dp[i][j] = dp[i][j - 1];
    }
    else if(j == 0 && i > 0) {
     dp[i][j] = dp[i - 1][j];
    }
    else {
     dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    }
   }
  }
   return dp[rows -1][cols - 1];

 }
};