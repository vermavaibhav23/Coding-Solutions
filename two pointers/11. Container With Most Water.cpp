//11. Container With Most Water
//Compiler - C++
//https://leetcode.com/problems/container-with-most-water/?envType=problem-list-v2&envId=two-pointers

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxx = INT_MIN;
        int l = 0;
        int r = height.size()-1;
        while(l < r) {
            int minn = min(height[l], height[r]);
            maxx = max(maxx, minn*(r-l));
            if(height[l] <= height[r]) {
                l++;
            }
            else {
                r--;
            }
        }
        return maxx;
    }
};