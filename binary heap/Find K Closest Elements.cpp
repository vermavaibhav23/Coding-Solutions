//Find K Closest Elements
//Compiler - C++
//https://leetcode.com/problems/find-k-closest-elements/

class Solution {
public:
    int mod(int x){
        if(x<0) {
            x = -1 * x;
        }
        return x;
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>>pq;
        for(auto it: arr) {
            pq.push({mod(x-it),it});
            if(pq.size() > k) {
                pq.pop();
            }
        }
        vector<int>ans;
        //sort_heap(pq.begin(), pq.end());
        while(!pq.empty()) {
            pair<int,int>temp = pq.top();
            ans.push_back(temp.second);
            pq.pop();
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};