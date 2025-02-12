LeetCode - Find Common Elements Between Two Arrays
Compiler - C++
https://leetcode.com/problems/find-common-elements-between-two-arrays/description/?envType=problem-list-v2&envId=array

class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        int answer1 = 0;
        int answer2 = 0;

    
        for (int num : nums1) {
            auto it = find(nums2.begin(), nums2.end(), num);
            if (it != nums2.end()) {
                answer1++;
            }
        }

       
        for (int num : nums2) {
            auto it = find(nums1.begin(), nums1.end(), num);
            if (it != nums1.end()) {
                answer2++;
            }
        }

        return {answer1, answer2};
    }
};