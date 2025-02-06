LeetCode - Remove Duplicates from Sorted Array
Compiler - C++
https://leetcode.com/problems/remove-duplicates-from-sorted-array/editorial/?envType=problem-list-v2&envId=array

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        int i=0,count=0;
        
        for (int j = 0; j<size; j++) {
            i=0;
            for (int z= (j+1) ; i<=0 && z<size; z++) {
                if (nums[j] == nums[z]) {
                    i++ ;
                }
            }
            if (i==0) {
                nums[count] = nums[j];
                count++ ;
            }
        }
        for (int b=0; b<size; b++) {
            cout<<nums[b]<<endl;
        }
    return count; 
    }
};