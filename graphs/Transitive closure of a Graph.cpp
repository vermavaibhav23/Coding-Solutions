//Transitive closure of a Graph
//Compiler - C++
//https://www.geeksforgeeks.org/problems/transitive-closure-of-a-graph0930/1

//Back-end complete function Template for C++

class Solution {
  public:
  
    map<int, vector<int>>adj_list(vector<vector<int>> graph, int N) {
        int i=0;
        map<int, vector<int>>m;
        for(auto edge : graph) {
            for(int j=0; j<N; j++) {
                if(graph[i][j] == 1) {
                    m[i].push_back(j);
                }
            }
            i++;
        }
        return m;
    }
    
    bool pathexists(int i, int j, map<int, vector<int>>adj, vector<bool>visited) {
        visited[i] = true;
        if(i == j) {
            return true;
        }
        for(auto it: adj[i]) {
            if(visited[it] == false){
                bool ans = pathexists(it,j,adj, visited);
                if(ans){
                    return true;
                }
            }
        }
        return false;
    }
    
    vector<vector<int>> transitiveClosure(int N, vector<vector<int>> graph) {
        // code here
        map<int, vector<int>>adj = adj_list(graph, N);
        vector<vector<int>> ans(N, vector<int>(N, 0));
        vector<bool>visited(N, false);
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++) {
                if(i==j || pathexists(i,j,adj,visited)) {
                    ans[i][j] = 1;
                }
            }
        }
        return ans;
    }
};