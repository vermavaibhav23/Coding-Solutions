//487. Max Consecutive Ones II
//Compiler : C++
//https://leetcode.com/problems/find-the-original-array-of-prefix-xor/description/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int l = 0;
        int r = 0;
        int count = 1;
        int zeros = 0;
        int zeropos = -1;

        while(r < nums.size()) {
            if(nums[r] == 0) {
                if(zeros == 0) {
                    zeros++;
                }
                else {
                    l = zeropos + 1;
                }
                zeropos = r;
            }
            count = max(count, r-l+1);
            r++;
        }

        return count;
    }
};