//Top K Frequent Elements
//Compiler - C++
//https://leetcode.com/problems/top-k-frequent-elements/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        for(int i=0; i<nums.size(); i++) {
            m[nums[i]]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pair<int,int>p;
        for(auto it: m) {
            p.first = it.second;
            p.second = it.first;
            pq.push(p);
            if(pq.size() > k) {
                pq.pop();
            }
        }
        vector<int>ans;
        while(!pq.empty()) {
            pair<int,int>u = pq.top();
            ans.push_back(u.second);
            pq.pop();
        }
        return ans;
    }
};