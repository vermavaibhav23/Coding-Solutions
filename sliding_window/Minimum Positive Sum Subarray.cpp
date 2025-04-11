//Minimum Positive Sum Subarray 
//Compiler - C++
//https://leetcode.com/problems/minimum-positive-sum-subarray/?envType=problem-list-v2&envId=sliding-window

class Solution {
public:
    int sum_of_elements(vector<int>v) {
        int sum = 0;
        for(int i=0; i<v.size(); i++) {
            sum = sum + v[i];
        }
        return sum;
    }
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int sum =-1000;
        int ans = INT_MAX;
        for(int window = l; window<=r; window++) {
            for(int i=0; i<= (nums.size() - window); i++) {
                vector<int>sub(nums.begin() + i, nums.begin() + i + window);
                sum = sum_of_elements(sub);
                cout<<sum<<endl;
                if(sum > 0 && sum < ans) {
                    ans = sum;
                }
            }
        }
        if (ans == INT_MAX) {
            return -1;
        }
        return ans;
    }
};