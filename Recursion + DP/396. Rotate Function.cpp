//396. Rotate Function
//C++
//https://leetcode.com/problems/rotate-function/description/

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int total = 0;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) { total += i*nums[i]; sum += nums[i]; }
        int to_exclude = nums.size() - 1;
        int maximum = total;
        for(int f = 1; f < nums.size(); f++) {
            int temp_sum = sum - nums[to_exclude];
            total = total + temp_sum - (nums[to_exclude] * (nums.size()-1)); 
            maximum = max(maximum, total);
            to_exclude--;
        }
        return maximum;
    }
};