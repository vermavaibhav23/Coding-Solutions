//1943. Describe the Painting
//Compiler - C++
//https://leetcode.com/problems/describe-the-painting/

class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        map<long long, long long> freq;
        for(auto it: segments) {
            freq[it[0]] += it[2];
            freq[it[1]] -= it[2];
        }
        vector<pair<long long, long long>> color;
        for(auto it: freq) {
            cout<<it.first<<", "<<it.second<<endl;
            color.push_back({it.first, it.second});
        }
        vector<vector<long long>> ans;
        long long last = 0;
        for(int i = 0; i < color.size()-1; i++) {
            vector<long long> temp;
            temp.push_back(color[i].first);
            temp.push_back(color[i+1].first);
            temp.push_back(color[i].second + last);
            last = temp.back();
            if(last != 0) ans.push_back(temp);
        }
        return ans;
    }
};