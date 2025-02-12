LeetCode - Find Words That Can Be Formed by Characters
Compiler - C++
https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/description/?envType=problem-list-v2&envId=array

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int total=0,final = 0,f=10;
        map<char,int>m1;
        for (int i=0; i< chars.size(); i++) {
            m1[chars[i]]++;
        }
        for (string word:words) {
            map<char,int>t1;
            for (char c:word) {
                t1[c]++;
            }
            for (auto it:t1) {
                if (m1.find(it.first) != m1.end() && m1[it.first] >= it.second) {
                    total++;
                }
            }
            if (total == t1.size()) {
                final += word.size();
            }
            total = 0;
        }
    return final;
    }
};