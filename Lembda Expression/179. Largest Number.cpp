//179. Largest Number
//Compiler - C++
//https://leetcode.com/problems/largest-number/

class Solution {
public:
    
    string largestNumber(vector<int>& nums) {
        auto myLambda = [] (int a, int b) {
            string s1 = to_string(a);
            string s2 = to_string(b);
            if(s1 + s2 > s2 + s1) {
                return true;
            }
            return false;
        };
        sort(nums.begin(), nums.end(), myLambda);
        
        if(nums[0] == 0) return "0";
        string ans = "";
        for(auto it: nums) {
            cout<<it<<endl;
            ans += to_string(it);
        }
        return ans;
    }
};