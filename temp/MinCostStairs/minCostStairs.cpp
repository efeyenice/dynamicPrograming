//
// Created by MacBook Pro on 10.10.2024.
//

#include <iostream>
#include <vector>

using namespace std;

int minCostClimbingStairs(const vector<int>& cost);
int main() {
    vector<int> cost;
    cost.push_back(10);
    cost.push_back(15);
    cost.push_back(20);
    int result= minCostClimbingStairs(cost);
    cout<<result<<endl;
}

int minCostClimbingStairs(const vector<int>& cost) {
    const int N = cost.size();
    int dp[N];
    int n = cost.size();
    dp[n - 1] = cost[n - 1];
    dp[n - 2] = cost[n - 2];

    for (int i = n - 3; i >= 0; i--) {
        dp[i] = cost[i] + min(dp[i + 1], dp[i + 2]);
    }

    return min(dp[0], dp[1]);

}