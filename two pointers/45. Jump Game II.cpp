//45. Jump Game II
//C++
//https://leetcode.com/problems/jump-game-ii/description/

class Solution {
public:
    int jump(vector<int>& nums) {
        int l = 0;
        int r = 0;
        pair<int,int> maximum;
        maximum.first = nums[0];
        maximum.second = 0;
        int ans = 0;

        while(r < nums.size()-1) {
            r = maximum.first;
            ans++;
            if(r >= nums.size()-1) return ans;
            maximum.first = INT_MIN;
            maximum.second = -1;
            int temp = l+1;
            while(temp <= r) {
                int far = temp + nums[temp];
                if(far > maximum.first) {
                    maximum.first = far;
                    maximum.second = temp;
                }
                temp++;
            }
            l = r;
        }
        return ans;
    }
};