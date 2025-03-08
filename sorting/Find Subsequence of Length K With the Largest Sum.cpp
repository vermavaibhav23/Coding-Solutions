//Find Subsequence of Length K With the Largest Sum
//Compiler - C++
//https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/description/?envType=problem-list-v2&envId=sorting

class Solution {
public:
    vector<int> sorting(vector<int> nums) {
    int n = nums.size();

    for (int i = 0; i < n - 1; i++) {
        int maxIdx = i;
        for (int j = i + 1; j < n; j++) { 
            if (nums[j] > nums[maxIdx]) { 
                maxIdx = j;
            }
        }
        swap(nums[i], nums[maxIdx]); 
    }
    return nums;
}
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int>descending = sorting(nums);
        vector<int>ans;
        for(int i=0; i<descending.size(); i++) {
            cout<<descending[i]<<endl;
        }
        unordered_map<int,int>m;
        int count = 0;
        for(int i=0; i<descending.size(); i++) {
            if(count >= k) {
                break;
            }
            m[descending[i]]++;
            count++;
        }

        for(auto it: nums) {
            if(m[it] > 0) {
                ans.push_back(it);
                m[it]--;
            }
        }
        return ans;
    }
};