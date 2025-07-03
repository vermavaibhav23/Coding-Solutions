//Cheapest Flights Within K Stops
//Compiler - C++
//https://leetcode.com/problems/cheapest-flights-within-k-stops/?envType=problem-list-v2&envId=graph

class Solution {
public:
    void helper(unordered_map<int, vector<pair<int,int>>>& adj, vector<bool>& visited, vector<vector<int>>& dp, int src, int dst, int k, int sum, int& minCost) {
        if (k < -1) return;
        if (src == dst) {
            minCost = min(minCost, sum);
            return;
        }

        if (dp[src][k + 1] != -1 && sum >= dp[src][k + 1]) return;
        dp[src][k + 1] = sum;

        visited[src] = true;

        for (auto it : adj[src]) {
            int node = it.first;
            int cost = it.second;
            if (visited[node]) continue;
            helper(adj, visited, dp, node, dst, k - 1, sum + cost, minCost);
        }

        visited[src] = false;
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int,int>>> adj;
        for (auto edge : flights) {
            int a = edge[0];
            int b = edge[1];
            int cost = edge[2];
            adj[a].push_back({b, cost});
        }

        int minCost = INT_MAX;
        vector<bool> visited(n, false);
        vector<vector<int>> dp(n, vector<int>(k + 2, -1));

        helper(adj, visited, dp, src, dst, k, 0, minCost);

        return minCost == INT_MAX ? -1 : minCost;
    }
};
