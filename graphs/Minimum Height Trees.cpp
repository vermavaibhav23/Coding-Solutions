//Minimum Height Trees
//Compiler - C++
//https://leetcode.com/problems/minimum-height-trees/?envType=problem-list-v2&envId=graph


class Solution {
public:
    queue<int>findCentre(vector<vector<int>>adj, vector<int>inorder) {
        queue<int>q;
        int nodes = inorder.size();
        while(nodes > 2){
            for(int i = 0; i < inorder.size() ; i++) {
                if(inorder[i] == 1) {
                    q.push(i);
                }
            }
            int size = q.size();
            for(int i = 0; i < size; i++) {
                int front = q.front();
                inorder[front] = -1;
                q.pop();
                nodes--;
                for(auto it: adj[front]) {
                    inorder[it]--;
                }
            }
        }
        for(int i = 0; i < inorder.size() ; i++) {
            if(inorder[i] == 1 || inorder[i] == 0) {
                q.push(i);
            }
        }
        return q;
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto it: edges) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool>visited(n, false);
        vector<int>inorder(n);
        for(int i=0; i<n; i++) {
            inorder[i] = adj[i].size();
        }
        queue<int>q = findCentre(adj, inorder);
        vector<int>res;
        while(!q.empty()){
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};