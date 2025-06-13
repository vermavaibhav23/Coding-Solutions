//Is Subsequence
//Compiler - C++
//https://leetcode.com/problems/is-subsequence/description/?envType=problem-list-v2&envId=dynamic-programming

class Solution {
public:
    bool helper(string s, int size, string t, int tize) {
        if(size == 0) {
            return true;
        }
        if(tize == 0) {
            return false;
        }

        if(s[size-1] == t[tize - 1]) {
            return helper(s,size-1,t,tize-1);
        }
        else return helper(s,size,t,tize-1);
    }
    bool isSubsequence(string s, string t) {
        return helper(s, s.size(), t, t.size());
    }
};