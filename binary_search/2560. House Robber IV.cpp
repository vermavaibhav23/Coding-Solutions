//2560. House Robber IV
//Compiler - C++
//https://leetcode.com/problems/house-robber-iv/description/

class Solution {
public:
    bool nonconsecutive_max(vector<int>nums, int k, int mid) {
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] <= mid) {
                i++;
                k--;
                if(k == 0) return true;
            }
        }
        return false;
    }
    int minCapability(vector<int>& nums, int k) {
        int l = *min_element(nums.begin(), nums.end());
        int r = *max_element(nums.begin(), nums.end());
        int ans = INT_MAX;
        while(l <= r) {
            int mid = l + (r - l)/2;
            cout<<mid<<endl;
            bool check = nonconsecutive_max(nums, k, mid);
            if(check) {
                cout<<"true"<<endl;
                r = mid - 1;
                ans = min(ans, mid);
            }
            else l = mid + 1;
        }
        return ans;
    }
};