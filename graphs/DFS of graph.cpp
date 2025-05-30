//DFS of graph
//Compiler - C++
//https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

class Solution {
  public:
    map<int, vector<int>>adj_list(vector<vector<int>> &adj) {
        int i = 0;
        map<int, vector<int>> m;
        for (auto it : adj) {
            m[i] = it; 
            i++;
        }
        return m;
    }
    
    void dfs_list(map<int, vector<int>>m, int size, int src, vector<bool>&visited, stack<int>&s, vector<int>&ans) {
        s.push(src);
        ans.push_back(src);
        visited[src] = true;
        for(auto it: m[src]) {
            if(visited[it] == false) {
                dfs_list(m,size,it,visited,s,ans);
                
            }
        }
        s.pop();
    }
    
    vector<int> dfs(vector<vector<int>>& adj) {
        map<int, vector<int>>m = adj_list(adj);
        vector<bool>visited(adj.size(),false);
        stack<int>s;
        vector<int>ans;
        dfs_list(m, adj.size(), 0, visited,s,ans);
        return ans;
    }
};