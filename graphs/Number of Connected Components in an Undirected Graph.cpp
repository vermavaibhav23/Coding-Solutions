//Number of Connected Components in an Undirected Graph
//Compiler - C++
//https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/?envType=problem-list-v2&envId=graph

class Solution {
public:
    void bfs(map<int, vector<int>> &adj , vector<bool>&v , int src) {
        queue<int>q;
        q.push(src);
        while(q.empty() == false) {
            int curr = q.front();
            q.pop();
            for(auto it:adj[curr]) {
                if(v[it] == false) {
                    q.push(it);
                    v[it] = true;
                }
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        map<int, vector<int>> adj;
        vector<bool>v(n,false);
        for(auto edge:edges) {
            int u=edge[0],vv=edge[1];
            adj[u].push_back(vv);
            adj[vv].push_back(u);
        }
        int count=0;
        for(int i=0; i<n; i++) {
            if(v[i] == false) {
                count++;
                bfs(adj,v,i);
            }
        }
        return count;
    }
};