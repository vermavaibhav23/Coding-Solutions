//1762. Buildings With an Ocean View
//C++
//https://leetcode.com/problems/buildings-with-an-ocean-view/?envType=company&envId=facebook&favoriteSlug=facebook-all

class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        vector<int> ans;
        ans.push_back(heights.size()-1);
        int max_ht = heights[heights.size()-1];
        for(int i = heights.size()-2; i >= 0; i--) {
            if(heights[i] > max_ht) {
                ans.push_back(i);
                max_ht = heights[i];
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};