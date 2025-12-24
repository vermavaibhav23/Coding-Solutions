//1353. Maximum Number of Events That Can Be Attended
//Compiler - C++
//https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        unordered_map<int, vector<int>> tasks_thatday(100000);
        for(int i = 0; i < events.size(); i++) {
            tasks_thatday[events[i][0]].push_back(events[i][1]);
        }
        priority_queue<int>pq;
        int curr_day = 1;
        int done = 0;
        
        while(curr_day <= 100000) {
            for(auto it: tasks_thatday[curr_day]) {
                pq.push(-1 * it);
            }
            while(pq.empty() == false && curr_day > -1 * pq.top()) {
                pq.pop();
            }
            if(pq.empty() == false) {
                done++;
                pq.pop();
            }
            curr_day++;
        }
        return done;
    }
};