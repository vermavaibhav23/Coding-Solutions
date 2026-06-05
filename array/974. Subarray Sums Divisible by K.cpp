//974. Subarray Sums Divisible by K
//Compiler : C++
//https://leetcode.com/problems/subarray-sums-divisible-by-k/

class Solution {
public:
    int mod(int x) {
        if(x < 0) x = -1 * x;
        return x;
    }
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> ps;
        ps.push_back(0);
        unordered_map<int, int> freq;
        freq[0]++;
        int ans = 0;

        for(int i = 0; i < nums.size(); i++) {
            int pre = ps.back() + nums[i];
            ps.push_back(pre);
            int rem = pre % k;
            if(rem < 0) rem = k + rem;
            ans += freq[rem];
            freq[rem]++;
        }

        return ans;
    }
};