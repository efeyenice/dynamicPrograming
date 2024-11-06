//
// Created by MacBook Pro on 19.10.2024.
//
//#define DEBUG

#include <vector>
#include <iostream>
using namespace std;


int deleteAndEarn(vector<int>& nums);
int countFrequency(vector<int>& nums, int k);


int main() {
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(3);

    int result = deleteAndEarn(nums);
    cout << result << endl;

}

int countFrequency(vector<int>& nums, int k) {
    int count = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == k) {
            count++;
        }
    }
    return count;
}


int deleteAndEarn(vector<int>& nums) {
    vector<int> frequencies(10000+1); //probably allocating more space than enough could be optimized
    for (int i = 0; i < nums.size(); i++) {
        int k = nums[i];
        frequencies[k] = countFrequency(nums, k);
    }
#ifdef DEBUG
    for(int i = 0; i < frequencies.size(); i++) {
        cout << frequencies[i] << endl;
    }
#endif

    int dp[frequencies.size()];
    dp[0] = 0;
    dp[1] = frequencies[1] * 1;
    for (int i = 2; i < frequencies.size(); i++) {
        dp[i] = max(dp[i-1], dp[i-2] + frequencies[i] * i);
    }


    return dp[frequencies.size()-1];
}
