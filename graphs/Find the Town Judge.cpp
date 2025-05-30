//Find the Town Judge
//Compiler - C++
//https://leetcode.com/problems/find-the-town-judge/?envType=problem-list-v2&envId=graph

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if (n == 1 && trust.empty()) return 1;
        unordered_map<int, vector<int>> graph;
        for(auto edge: trust) {
            int u = edge[1];
            int v = edge[0];
            graph[u].push_back(v); 
        }
        vector<int>ans;
        for(auto it: graph) {
            if(it.second.size() == n-1) {
                ans.push_back(it.first);
            }
        }

        for(auto it:graph){
            for(int i=0; i<it.second.size(); i++){
                for(int j=0; j<ans.size(); j++){
                    if(ans[j] == it.second[i]) {
                        ans[j] = -2;
                    }
                }
            }
        }

        for(int i=0; i<ans.size(); i++) {
            //cout<<ans[i]<<endl;
            if(ans[i] != -2) {
                return ans[i];
            }
        }
        return -1;
    }
};