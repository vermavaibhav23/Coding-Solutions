LeetCode - Merge Similar Items
Compiler - C++
https://leetcode.com/problems/merge-similar-items/description/?envType=problem-list-v2&envId=array

class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        map<int,int>f1;
        map<int,int>f2;
        vector<vector<int>> ret;
        for (int i=0; i< (items1.size()); i++) {
            f1[items1[i][0]] = items1[i][1];
        }
        for (int i=0; i< (items2.size()); i++) {
            f2[items2[i][0]] = items2[i][1];
        }

        for (auto a:f1) {
            int key = a.first;
            int value = a.second;
            if (f2.find(a.first) != f2.end()) {
                value = value + f2[key];
            }
            ret.push_back({key,value});
        }
        for (auto b:f2) {
            if (f1.find(b.first) == f1.end()) {
                ret.push_back({b.first,b.second});
            }
        }
       sort(ret.begin(), ret.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
    return ret;
    }
};