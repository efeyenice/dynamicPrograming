
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));

        //to keep track of the longest palindrome
        int start;
        int maxLen = 0;


        //base cases:

        //single-character substring
        for (int i = 0; i < s.size(); i++) {
            dp[i][i] = true;
            start = i;
            maxLen = 1;
        }
        if (s.size() == 1) {
            return s.substr(start, maxLen);
        }





        //two-character substring
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                start = i;
                maxLen = 2;
            }
        }
        if (s.size() == 2) {
            return s.substr(start, maxLen);
        }




        //filling the dp
        for (int len = 3; len <= s.size(); len++) {
            for (int i = 0; i + len <= s.size(); i++) {
                int j = i + len - 1;
                //transition relation
                if (s[i] == s[j] && dp[i+1][j-1]) {
                    dp[i][j] = true;
                    if (len > maxLen) {
                        start = i;
                        maxLen = len;
                    }

                }
            }
        }

        return s.substr(start, maxLen);



    }
};