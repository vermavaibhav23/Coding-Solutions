//162. Find Peak Element
//Compiler - C++
//https://leetcode.com/problems/find-peak-element/?envType=company&envId=facebook&favoriteSlug=facebook-six-months

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1 || nums[0] > nums[1]) return 0;
        else if(nums[nums.size()-1] > nums[nums.size()-2]) return nums.size()-1;

        int l = 1;
        int r = nums.size()-2;

        while(l <= r) {
            int mid = l + (r-l)/2;
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) return mid;

            if(nums[mid-1] > nums[mid]) r = mid - 1;
            else l = mid + 1;
        }
        return -1;
    }
};