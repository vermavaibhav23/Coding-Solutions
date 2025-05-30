//Connected Components in an Undirected Graph
//Compiler - C++
//https://www.geeksforgeeks.org/problems/connected-components-in-an-undirected-graph/1


class Solution {
  public:
  
    vector<vector<int>> adj_list(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return adj;
    }

    void traverse(vector<vector<int>>& adj, int src, vector<bool>& visited, vector<int>& v) {
        visited[src] = true;
        v.push_back(src);
        for (int neighbor : adj[src]) {
            if (!visited[neighbor]) {
                traverse(adj, neighbor, visited, v);
            }
        }
    }

    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj = adj_list(V, edges);
        vector<vector<int>> ans;
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                vector<int> component;
                traverse(adj, i, visited, component);
                ans.push_back(component);
            }
        }
        return ans;
    }
};


