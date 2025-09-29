//1636. Sort Array by Increasing Frequency
//Compiler - C++
//https://leetcode.com/problems/sort-array-by-increasing-frequency/

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(auto it: nums) {
            freq[it]++;
        }
        auto mylembda = [&freq](int a, int b) {
            //if(a == b) return true;
            if(freq[a] == freq[b]) {
                if(a > b) return true;
                return false;
            }
            if(freq[a] < freq[b]) {
                return true;
            }
            return false;
        };
        sort(nums.begin(), nums.end(), mylembda);
        return nums;
    }
};




