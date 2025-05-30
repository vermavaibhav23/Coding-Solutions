//BFS of graph
//Compiler - C++
//https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

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
    
    vector<int> bfs_list(map<int, vector<int>>m, int size) {
        vector<int>visited(size,false);
        queue<int>q;
        q.push(0);
        visited[0] = true;
        vector<int>ans;
        while(!q.empty()) {
            int temp = q.front();
            q.pop();
            ans.push_back(temp);
            vector<int>v = m[temp];
            for(int i=0; i < m[temp].size(); i++) {
                if(visited[v[i]] == false) {
                    q.push(v[i]);
                    visited[v[i]] = true;
                }
            }
        }
        return ans;
    }
    
    
    vector<int> bfs(vector<vector<int>> &adj) {
        map<int, vector<int>>m = adj_list(adj);
        vector<int>ans = bfs_list(m, adj.size());
        return ans;
    }
};