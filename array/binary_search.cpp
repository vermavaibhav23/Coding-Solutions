LeetCode - Binary Search
Compiler - C++
https://leetcode.com/problems/binary-search/description/?envType=problem-list-v2&envId=array

class Solution {
public:
    int exists(vector<int>& nums, int target, int start, int end){
         if(start > end){
            return -1;
        }
        int mid = (start + end)/2;
        
        if(nums[mid] == target){
            return mid;
        }
       
        if(nums[mid]>target){
            return exists(nums,target,start,mid-1);
        }
        else return exists(nums, target, mid+1, end); 
    }
    int search(vector<int>& nums, int target) {
        int start = 0;
        int size = nums.size();
        int end = size-1;
        int mid = (start + end)/2;
        int ans = exists(nums,target,start,end);
        return ans;
        
    }
};