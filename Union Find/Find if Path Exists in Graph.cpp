//Find if Path Exists in Graph
//Compiler - C++
//https://leetcode.com/problems/find-if-path-exists-in-graph/?envType=problem-list-v2&envId=union-find

class Solution {
public:
    int findParent(int x, vector<int>& parent) {
        if(parent[x] == x) return x;
        return parent[x] = findParent(parent[x], parent);
    }
    void unionn(int x, int y, vector<int>& parent) {
        int x_parent = findParent(x, parent);
        int y_parent = findParent(y, parent);
        if(x_parent != y_parent) {
            parent[y_parent] = x_parent;
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int>parent(n);
        for(int i=0 ; i<n; i++) {
            parent[i] = i;
        }
        for(auto it: edges) {
            int u = it[0];
            int v = it[1];
            unionn(u, v, parent);
        }
        int src_parent = findParent(source, parent);
        int dest_parent = findParent(destination, parent);
        if(src_parent == dest_parent) return true;
        else return false;
    }
};