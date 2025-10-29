//28. Find the Index of the First Occurrence in a String
//Compiler - C++
//https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/?envType=problem-list-v2&envId=two-pointers

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() > haystack.size()) {
            return -1;
        }
        int start = needle[0];
        for(int i = 0; i < haystack.size(); i++) {
            if(haystack[i] == start) {
                string temp = haystack.substr(i, needle.size());
                if(temp == needle) return i;
            }
        }
        return -1;
    }
};