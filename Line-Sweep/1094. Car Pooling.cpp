//1094. Car Pooling
//Compiler - C++
//https://leetcode.com/problems/car-pooling/description/

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<vector<int>> car;
        for(auto it : trips) {
            int people = it[0];
            int from = it[1];
            int to = it[2];
            car.push_back({from, people});
            car.push_back({to, -1 * people});
        }
        sort(car.begin(), car.end());
        int curr = 0;
        for(int i = 0; i < car.size(); i++) {
            curr = curr + car[i][1];
            if(curr > capacity) return false;
        }
        return true;
    }
};