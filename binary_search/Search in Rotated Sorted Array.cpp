//Search in Rotated Sorted Array
//Compiler - C++
//https://leetcode.com/problems/search-in-rotated-sorted-array/?envType=problem-list-v2&envId=binary-search

class Solution {
public:
    int binary_srch(vector<int>& nums, int target, int front, int back) {
        int mid = (front+back)/2;
        if(front > back) {
            return -1;
        }
        if(nums[mid] == target) {
            return mid;
        }
        if(nums[mid] > target) {
            return binary_srch(nums,target,front,mid-1);
        }
        else return binary_srch(nums,target,front+1,back);
    }
    int search(vector<int>& nums, int target) {
        int front = 0;
        int back = nums.size() - 1;
        int mid;
        while(front != back) {
            mid = (front + back)/2;
            if(nums[mid] >= nums[back]) {
                front = mid + 1;
            }
            else back = mid;
        }
        int pivot = front;
        int ans = binary_srch(nums,target,0,pivot-1);
        if(ans == -1) {
            ans = binary_srch(nums,target,pivot,nums.size()-1);
        }
        return ans;
    }
};