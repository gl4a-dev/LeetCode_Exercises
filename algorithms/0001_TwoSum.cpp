// 1. TWO SUM

//Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target. You may assume that each input would have exactly one solution, and you may not use the same element twice. You can return the answer in any order.

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map<int, int> map;

            for(int i = 0; i < nums.size(); i++){
                int compliment = target - nums[i];
                
                if(map.find(compliment) != map.end()) return {map[compliment], i};
                map[nums[i]] = i;
            }
            
            return {};
        }
};

int main() {
    Solution s;

    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = s.twoSum(nums, target);

    cout << result[0] << ", " << result[1] << endl;
}
