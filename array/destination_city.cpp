LeetCode - Destination City
Compiler - C++
https://leetcode.com/problems/destination-city/description/?envType=problem-list-v2&envId=array

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        int size = paths.size();
        int count = 0; 
        int j;
        unordered_set <string> s;
        for (int i=0; i<size; i++) {
            s.insert(paths[i][0]);
        }
        for (j=0; j<size; j++) {
            count = 0;
            auto it = s.find(paths[j][1]) ;
            if (it != s.end()) {
                count++;
            }
            if (count == 0) {
                return paths[j][1];
            }
        }
    return paths[j][1];
    }
};