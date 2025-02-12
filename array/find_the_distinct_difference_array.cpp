LeetCode - Find the Distinct Difference Array
Compiler - C++
https://leetcode.com/problems/find-the-distinct-difference-array/description/?envType=problem-list-v2&envId=array

class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        set<int>p;
        set<int>s;
        int size = nums.size();
        vector <int> arr(size);

        for (int i=0; i<size; i++) {
            p.clear();
            s.clear();
            for (int j=0; j<=i; j++) {
                p.insert(nums[j]);
            }
            for (int z=(i+1); z<size; z++) {
                s.insert(nums[z]);
            }
            arr[i] = (p.size() - s.size());

        } 
    return arr;  
    }
};