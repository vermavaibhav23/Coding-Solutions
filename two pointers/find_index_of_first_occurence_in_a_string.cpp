LeetCode - Find the Index of the First Occurrence in a String
Compiler - C++
https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/?envType=problem-list-v2&envId=two-pointers

class Solution {
public:
    int strStr(string haystack, string needle) {
        int i=0;
        int j=0;
        string s;
        int nsize = needle.size();
        int ans = -1;
        for(i=0; i< haystack.size(); i++) {
            if( haystack[i] == needle[j]) {
                s = haystack.substr(i,nsize);
                if (s == needle) {
                    ans = i;
                    break;
                }
            }
        }
        return ans;
    }
};