LeetCode - Count Elements With Maximum Frequency
Compiler - C++
https://leetcode.com/problems/count-elements-with-maximum-frequency/description/?envType=problem-list-v2&envId=array

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int maxfre = 0, totalfre = 0;
        map<int , int> fre;
        for (int i=0; i< (nums.size()); i++) {
            fre[nums[i]]++ ;
        }
        
        for (auto it = fre.begin(); it != fre.end(); ++it) {
            int freq = it->second;;
            if (freq >= totalfre) {
                if (freq > totalfre) {
                    maxfre = 0;
                    maxfre = maxfre + freq;
                    totalfre = freq;
                }
                else if (freq == totalfre) {
                    maxfre = maxfre + freq;
                }
            }
        }
    return maxfre;
    }
};