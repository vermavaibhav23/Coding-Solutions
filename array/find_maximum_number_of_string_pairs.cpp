LeetCode - Find Maximum Number of String Pairs
Compiler - C++
https://leetcode.com/problems/find-maximum-number-of-string-pairs/description/?envType=problem-list-v2&envId=array

class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int pair =0; int size = words.size();
        set<string>seen;
        for (int i=0; i<size; i++) {
            string letter;
            int a = (words[i]).size();
            for (int j = a-1; j>=0; j--) {
                letter += words[i][j];
            }
            if (seen.find(letter) == seen.end()) {
                seen.insert(words[i]);
            }
            else {
                seen.erase(letter);
                pair++;
            }

        }
    return pair;
    }
};