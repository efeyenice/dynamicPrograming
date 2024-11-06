//
// Created by MacBook Pro on 10.10.2024.
//


//your algorithms did not work, dumbass



#include <vector>
#include <iostream>
using namespace std;


int rob(vector<int>& nums);
int indexOfLeastLosingHouse(vector<int>& nums);
bool everyHouseProcessed(vector<int>& nums);

int main() {
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(9);
    nums.push_back(3);
    nums.push_back(1);
    int result = rob(nums);
    cout << result << endl;


}

int rob(vector<int>& nums) {
    int money = 0;

    if (nums.size() == 1) {
        return nums[0];
    }
    else if (nums.size() == 2) {
        return max(nums[0], nums[1]);
    }

    int index = 0;
    while (!everyHouseProcessed(nums)) {
        index = indexOfLeastLosingHouse(nums);
        if (index == 0) {
            money += nums[index];
            nums[index] = -1;
            nums[index + 1] = -1;
        }
        else if (index == nums.size() - 1) {
            money += nums[index];
            nums[index] = -1;
            nums[index - 1] = -1;
        }
        else {
            money += nums[index];
            nums[index] = -1;
            nums[index + 1] = -1;
            nums[index - 1] = -1;
        }
    }

    return money;
}


//a better programmer would divide this function to smaller ones
int indexOfLeastLosingHouse(vector<int>& nums) {
    int indexOfLeastLosingHouse = -1;
    int minLoss = 100000;
    int currentLoss = 0;
    for (int i = 0; i < nums.size(); i++) {
        if(i == 0 && nums[i] != -1) {
            if(nums[i+1] != -1) {
                currentLoss = nums[i+1];
                if (currentLoss <= minLoss) {
                    minLoss = currentLoss;
                    indexOfLeastLosingHouse = i;
                }
            }
            else {
                currentLoss = 0;
                if (currentLoss <= minLoss) {
                    minLoss = currentLoss;
                    indexOfLeastLosingHouse = i;
                }
            }
        }
        else if (i == nums.size()-1 && nums[i] != -1) {
            if(nums[i-1] != -1) {
                currentLoss = nums[i-1];
                if (currentLoss <= minLoss) {
                    minLoss = currentLoss;
                    indexOfLeastLosingHouse = i;
                }
            }
            else {
                currentLoss = 0;
                if (currentLoss <= minLoss) {
                    minLoss = currentLoss;
                    indexOfLeastLosingHouse = i;
                }
            }
        }
        else if (nums[i] != -1) {
            if(nums[i-1] != -1 && nums[i+1] != -1) {
                currentLoss = nums[i+1] + nums[i-1];
                if (currentLoss <= minLoss) {
                    minLoss = currentLoss;
                    indexOfLeastLosingHouse = i;
                }
            }
            else if (nums[i-1] != -1 && nums[i+1] == -1) {
                currentLoss = nums[i-1];
                if (currentLoss <= minLoss) {
                    minLoss = currentLoss;
                    indexOfLeastLosingHouse = i;
                }
            }
            else if (nums[i-1] == -1 && nums[i+1] != -1) {
                currentLoss = nums[i+1];
                if (currentLoss <= minLoss) {
                    minLoss = currentLoss;
                    indexOfLeastLosingHouse = i;
                }
            }
            else {
                currentLoss = 0;
                if (currentLoss <= minLoss) {
                    minLoss = currentLoss;
                    indexOfLeastLosingHouse = i;
                }
            }
        }
    }
    return indexOfLeastLosingHouse;
}

bool everyHouseProcessed(vector<int>& nums) {
    int cnt = 0;
    for(int i = 0; i < nums.size(); i++) { // NOLINT(*-loop-convert)
        if(nums[i] == -1) {
            cnt++;
        }
    }
    return cnt == nums.size();
}

