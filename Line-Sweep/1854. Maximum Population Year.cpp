//1854. Maximum Population Year
//Compiler - C++
//https://leetcode.com/problems/maximum-population-year/description/

class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<vector<int>> people;
        for(auto it : logs) {
            people.push_back({it[0], 1});
            people.push_back({it[1], -1});
        }
        sort(people.begin(), people.end());
        int ans = logs[0][0];
        int curr_pop = 0;
        int max_pop = INT_MIN;
        for(int i = 0; i < people.size(); i++) {
            curr_pop += people[i][1];
            if(curr_pop > max_pop) {
                ans = people[i][0];
                max_pop = curr_pop;
            }
        }
        return ans;
    }
};