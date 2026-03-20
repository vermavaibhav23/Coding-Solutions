//338. Counting Bits
//Compiler : C++
//https://leetcode.com/problems/counting-bits/

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i = 0; i <= n; i++) {
            int ones = 0;
            int num = i;
            while(num != 0) {
                if((num & 1) == 1) ones++;
                num = num >> 1;
            }
            ans.push_back(ones);
        }
        return ans;
    }
};