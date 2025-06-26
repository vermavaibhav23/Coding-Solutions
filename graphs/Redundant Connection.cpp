//Redundant Connection
//Compiler - C++
//https://leetcode.com/problems/redundant-connection/?envType=problem-list-v2&envId=graph


class Solution {
public:
    int find(int x, map<int, int>&parent) {
        if(parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent[x], parent);
    }

    void unionn(int x, int y, map<int, int>&parent) {
        int x_parent = find(x, parent);
        int y_parent = find(y, parent);
        if(x_parent != y_parent) {
            parent[y_parent] = x_parent;
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int vertices = edges.size();
        map<int, int> parent;
        for(int i=1; i<=vertices; i++) {
            parent[i] = i;
        }
        for(auto it: edges) {
            int u = it[0];
            int v = it[1];
            int u_parent = find(u, parent);
            int v_parent = find(v, parent);
            if(u_parent == v_parent) return it;
            else unionn(u,v, parent);
        }
        return {};
    }
};
