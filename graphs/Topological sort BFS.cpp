//Topological sort
//Compiler - C++
//https://www.geeksforgeeks.org/problems/topological-sort/1

class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        map<int, vector<int>>adj;
        for(auto edge: edges) {
            int u=edge[0],v=edge[1];
            adj[u].push_back(v);
        }
        
        vector<int>in(V,0);
        
        for(int i=0; i<edges.size(); i++) {
            in[edges[i][1]]++;
        }
        queue<int>q;
        for(int i=0; i<V; i++) {
            if(in[i] == 0) {
                q.push(i);
            }
        }
        vector<int>ans;
        while(q.empty() == false) {
            int curr = q.front();
            q.pop();
            ans.push_back(curr);
            for(auto it: adj[curr]) {
                in[it]--;
                if(in[it] == 0) {
                    q.push(it);
                }
            }
        }
        return ans;
    }
};