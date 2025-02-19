LeetCode - Number of Distinct Averages
Compiler - C++
https://leetcode.com/problems/number-of-distinct-averages/?envType=problem-list-v2&envId=two-pointers

class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        set <double> s;
        sort(nums.begin(),nums.end());
        int size = nums.size();
        int i=0;
        int j = size-1;
        while(j>i) {
            s.insert((nums[i] + nums[j])/2.0);
            i++;
            j--;
        }
        for(double num: s){
            cout<<num<<endl;
        }
        return s.size();
    }
};