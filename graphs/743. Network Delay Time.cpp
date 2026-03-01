//743. Network Delay Time
//Compiler - C++
//https://leetcode.com/problems/network-delay-time/description/

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for(auto it: times) {
            adj[it[0]].push_back({it[1], it[2]});
        }
        vector<int> dist(n+1, INT_MAX);
        dist[0] = INT_MIN;
        dist[k] = 0;
        set<pair<int, int>> s;
        s.insert({0, k});

        while(s.empty() == false) {
            auto it = s.begin();
            int curr = it->second;
            int time = it->first;
            s.erase(*it);
            for(auto i: adj[curr]) {
                if(dist[i.first] > time + i.second) {
                    s.erase({dist[i.first], i.first});
                    s.insert({time + i.second, i.first});
                    dist[i.first] = time + i.second;
                }
            }
        }
        int maxi = INT_MIN;
        for(auto it: dist) maxi = max(maxi, it);
        if(maxi == INT_MAX) return -1;
        return maxi;
    }
};