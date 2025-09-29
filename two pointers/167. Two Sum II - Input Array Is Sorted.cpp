//167. Two Sum II - Input Array Is Sorted
//Compiler - C++
//https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/?envType=company&envId=microsoft&favoriteSlug=microsoft-thirty-days

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size()-1;
        while(l < numbers.size() && r >= 0) {
            int temp = numbers[l] + numbers[r]; 
            if(temp == target) {
                return {l+1, r+1};
            }
            else if (temp > target) {
                r--;
            }
            else l++;
        }
        return {0,0};
    }
};