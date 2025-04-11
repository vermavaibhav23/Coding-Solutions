//Minimum Difference Between Highest and Lowest of K Scores
//Compiler - C++
//https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/?envType=problem-list-v2&envId=sliding-window

class Solution {
public:
    vector<int> selection_sort(vector<int>& nums) {
        
        for(int i=0; nums.size() >= 2 && i<= nums.size() -2; i++){
            int min = i;
            for(int j=i; j< nums.size() ; j++) {
                if(nums[j] < nums[min]){
                    min = j;
                }
            }
            int temp = nums[min];
            nums[min] = nums[i];
            nums[i] = temp;
        }
        return nums;
    }

    int minimum_element(vector<int>& v, int a, int b) {
        int min = 1000000;
        for(int i=a; i<=b; i++) {
            if(v[i] < min) {
                min = v[i];
            }
        }
        return min;
    }

    int maximum_element(vector<int>& v, int a, int b) {
        int max = -1*1000000;
        for(int i=a; i<=b; i++) {
            if(v[i] > max) {
                max = v[i];
            }
        }
        return max;
    }

    int minimumDifference(vector<int>& nums, int k) {
        if(nums.size() < 2) {
            return 0;
        }
        nums = selection_sort(nums);
        vector<int>v;
        
        for(int i=0; i<= nums.size() - k; i++) {
            int mi,ma;
            mi = minimum_element(nums,i,i+k-1);
            ma = maximum_element(nums,i,i+k-1);
            v.push_back(ma - mi);
        }
        return minimum_element(v,0,v.size() - 1);
    }
};