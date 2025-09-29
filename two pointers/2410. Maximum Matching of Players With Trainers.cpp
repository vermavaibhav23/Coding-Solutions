//2410. Maximum Matching of Players With Trainers
//Compiler - C++
//https://leetcode.com/problems/maximum-matching-of-players-with-trainers/description/

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int i = players.size()-1;
        int j = trainers.size()-1;
        int ans = 0;
        while(i >= 0 && j >= 0) {
            if(players[i] <= trainers[j]) {
                i--;
                j--;
                ans++;
            }
            else {
                i--;
            }
        }
        return ans;
    }
};