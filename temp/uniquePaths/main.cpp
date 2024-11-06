#include <algorithm>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        int r = n -1; //number of moves we need to take to reach the right-end
        int d = m -1; //number of moves we need to take to reach the bottom

        //we use repeated permutation to find unique paths
        //put everything below in a function
        int z = r + d - max(r, d);
        double result = 1;
        for(int i = 0; i < z; i ++){
            result *= (r + d) - i;
        }
        int k = min(r, d);
        for(int i = 0; i < k; i++){
            result = result / (k-i);
        }
        return result;


    }
};