//42. Trapping Rain Water
//C++
//https://leetcode.com/problems/trapping-rain-water/?envType=problem-list-v2&envId=two-pointers

class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> left(height.size(), 0);
        for(int i = 0; i < height.size(); i++) {
            if(i == 0) left[i] = height[i];
            else left[i] = max(left[i-1], height[i]);
        }

        vector<int> right(height.size(), 0);
        for(int i = height.size() - 1; i >= 0; i--) {
            if(i == height.size() - 1) right[i] = height[i];
            else right[i] = max(right[i+1], height[i]);
        }
        long long ans = 0;
        for(int i = 0; i < height.size(); i++) {
            ans += min(left[i], right[i]) - height[i];
        }
        return ans;
    }
};