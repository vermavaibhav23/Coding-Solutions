LeetCode - How Many Numbers Are Smaller Than the Current Number
Compiler - C++
https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/description/?envType=problem-list-v2&envId=array

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int size = nums.size();
        int frequency[101];
        
        for (int i=0; i<size; i++) {
            frequency[nums[i]] ++ ;
        }
        for (int j=1; j<101; j++) {
            frequency[j] = frequency[j] + frequency[j-1];
        }
        for (int z=0; z<size; z++) {
            int position = nums[z];
            if (position == 0) nums[z] = 0;
            else{
            nums[z] = frequency[position - 1];
            }
            
        }
    return nums;
    }
};