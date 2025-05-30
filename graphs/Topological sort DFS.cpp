//Topological sort
//Compiler - C++
//https://www.geeksforgeeks.org/problems/topological-sort/1

class Solution {
  public:
  
    void dfs(map<int, vector<int>>&adj, stack<int>&s, vector<bool>&v, int src){
        v[src] = true;
        int count=0;
        
        for(auto it:adj[src]) {
            if(v[it] == false) {
                count++;
                dfs(adj,s,v,it);
            }
        }
        
        s.push(src);
        
    }
    
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        map<int, vector<int>>adj;
        vector<bool>v(V,false);
        for(auto edge: edges) {
            int u=edge[0],vi=edge[1];
            adj[u].push_back(vi);
        }
        
        stack<int>s;
        
        for(int i=0; i<V; i++){
            if(v[i] == false){
                dfs(adj,s,v,i);
            }
        }
        
        vector<int>ans;
        while(s.empty()==false) {
            int curr = s.top();
            s.pop();
            ans.push_back(curr);
        }
        return ans;
    }
};