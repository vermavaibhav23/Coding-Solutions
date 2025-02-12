LeetCode - Make Two Arrays Equal by Reversing Subarrays
Compiler - C++
https://leetcode.com/problems/make-two-arrays-equal-by-reversing-subarrays/description/?envType=problem-list-v2&envId=array

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int c=0;
        map <int, int> m1;
        map <int, int> m2;
        for (int i=0; i< target.size(); i++) {
            m1[target[i]]++;
            m2[arr[i]]++;
        }
        for (auto it: m1) {
            if (m2.find(it.first) != m2.end() && m1[it.first] == m2[it.first]) {
                c++ ;
            }
        }
        if (c == m1.size() && c == m2.size()) {
            return true;
        }
    return false;
    }
};