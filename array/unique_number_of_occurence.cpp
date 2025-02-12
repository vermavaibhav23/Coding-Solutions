LeetCode - Unique Number of Occurrences
Compiler - C++
https://leetcode.com/problems/unique-number-of-occurrences/description/?envType=problem-list-v2&envId=array

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int>m1;
        for (int i=0; i< arr.size(); i++) {
            m1[arr[i]] ++;
        }
        map <int, int> m2;
        for (auto it: m1) {
            m2[it.second]++;
        }
        if (m1.size() == m2.size()) {
            return true;
        }
    return false;
    }
};