//137. Single Number II
//Compiler : C++
//https://leetcode.com/problems/single-number-ii/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < 32; i++) {
            int zeros = 0;
            int ones = 0;
            int temp = 1 << i;

            for(auto it: nums) {
                if((it & temp) == 0) zeros++;
                else ones++;
            }

            if(ones % 3 != 0) ans = (ans | 1<<i);
        }
        return ans;
    }
};