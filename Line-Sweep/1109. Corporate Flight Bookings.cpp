//1109. Corporate Flight Bookings
//Compiler - C++
//https://leetcode.com/problems/corporate-flight-bookings/description/

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        map<int,int> freq;
        for(auto it : bookings) {
            freq[it[0]] += it[2];
            freq[it[1]+1] -= it[2];
        }
        vector<int> ans;
        int last = 0;
        for(int i = 1; i <= n; i++) {
            ans.push_back(last + freq[i]);
            last = ans.back();
        }
        return ans;
    }
};