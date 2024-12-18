//
// Created by MacBook Pro on 18.12.2024.
//


//terrible solution

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
      vector<bool> dp(s.size()+1, false);
      dp[0] = true;

      for(int i = 1; i <= s.size(); i++){
        for(int j = 0; j < s.size(); j++){
          string checkWord = s.substr(j,i-j);
          bool wordExist = false;
          for(int k = 0; k < wordDict.size(); k++){ if(checkWord == wordDict[k]) {wordExist = true;}}
          if(dp[j] && wordExist){dp[i] = true; break;}
        }
      }



      return dp[s.size()];
    }



};
