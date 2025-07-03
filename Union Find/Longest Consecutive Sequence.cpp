//Longest Consecutive Sequence
//Compiler - C++
//https://leetcode.com/problems/longest-consecutive-sequence/?envType=problem-list-v2&envId=union-find

class Solution {
public:
    int findParent(int x, unordered_map<int, int>& parent) {
    if (x != parent[x]) {
        parent[x] = findParent(parent[x], parent); 
    }
    return parent[x];
    }
    void unionn(int x, int y, unordered_map<int, int>&parent, unordered_map<int, int>& size) {
        int x_parent = findParent(x, parent);
        int y_parent = findParent(y, parent);
        if(x_parent != y_parent) {
            if (size[x_parent] < size[y_parent]) {
                swap(x_parent, y_parent); 
            }
            parent[y_parent] = x_parent;
            size[x_parent] += size[y_parent];
        }
    }
    int longestConsecutive(vector<int>& nums) {
        int count = 0;
        unordered_map<int, int> parent;
        unordered_map<int, int> size;
        unordered_set<int> numSet(nums.begin(), nums.end());
        for (int num : numSet) {
            parent[num] = num;
            size[num] = 1;
        }

        for (int num : numSet) {
            if (numSet.find(num + 1) != numSet.end()) {
                unionn(num, num + 1, parent, size);
            }
        }
        int c = 0;
        for(auto it: size) {
            if(it.second > c) {
                c = it.second;
            }
        }
        return c;
    }
};