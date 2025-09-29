//763. Partition Labels
//Compiler - C++
//https://leetcode.com/problems/partition-labels/

class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, vector<int>>freq;
        for(int i = 0; i < s.size(); i++) {
            if(freq[s[i]].size() >= 2) {
                freq[s[i]].pop_back();
            }
            freq[s[i]].push_back(i);
        }
        vector<int>ans;
        int i = 0;
        int j = 0;
        int k = 0;
        while(k < s.size()) {
            int temp = freq[s[j]].back();
            if(k < temp) {
                k = temp;
            }
            if(j == k) {
                ans.push_back(k-i+1);
                i = k+1;
                j= k+1;
                k = k+1;
                continue;
            }
            j++;
        }
        return ans;
    }
};