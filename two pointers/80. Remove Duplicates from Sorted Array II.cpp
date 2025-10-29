//80. Remove Duplicates from Sorted Array II
//Compiler - C++
//https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/?envType=problem-list-v2&envId=two-pointers

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int,int> freq;
        int index = 1;
        int count = 1;
        for(int i = 1; i < nums.size(); i++) {
            if( nums[i] == nums[i-1]) {
                count++;
                if(count > 2) {
                    continue;
                }
            }
            else count = 1;
            nums[index] = nums[i];
            index++;
        }
        cout<<index+1<<endl;
        return index;
    }
};