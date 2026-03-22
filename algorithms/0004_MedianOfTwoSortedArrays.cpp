// 4. MEDIAN OF TWO SORTED ARRAYS

// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.The overall run time complexity should be O(log (m+n)).

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        int m = nums1.size(), n = nums2.size();
        int merge_size = m + n;

        int start_index = 0, end_index = m;
        while(start_index <= end_index){
            int n1_partition_index = (end_index + start_index)/2;
            int n2_partition_index = (merge_size + 1)/2 - n1_partition_index;

            int n1_partition_left = (n1_partition_index == 0) ? INT_MIN : nums1[n1_partition_index - 1];
            int n1_partition_right = (n1_partition_index == m) ? INT_MAX : nums1[n1_partition_index];
            int n2_partition_left = (n2_partition_index == 0) ? INT_MIN : nums2[n2_partition_index - 1];
            int n2_partition_right = (n2_partition_index == n) ? INT_MAX : nums2[n2_partition_index];

            if(n1_partition_left > n2_partition_right)
                end_index = n1_partition_index - 1;

            else if(n2_partition_left > n1_partition_right)
                start_index = n1_partition_index + 1;

            else {
                if(merge_size % 2 == 0) 
                    return (double) (max(n1_partition_left, n2_partition_left) + min(n1_partition_right, n2_partition_right))/2;
                else 
                    return (double) max(n1_partition_left, n2_partition_left);
            }
        }
        return 0.0;
    }
};

int main(){
    Solution s;

    vector<int> nums1 = {1, 3, 8, 9, 15};
    vector<int> nums2 = {7, 11, 18, 19, 21, 25};

    double result = s.findMedianSortedArrays(nums1, nums2);
    cout << result << endl;
}