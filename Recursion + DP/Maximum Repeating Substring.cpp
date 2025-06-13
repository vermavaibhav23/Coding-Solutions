//Maximum Repeating Substring
//Compiler - C++
//https://leetcode.com/problems/maximum-repeating-substring/?envType=problem-list-v2&envId=dynamic-programming

class Solution {
public:
    bool substring(string sequence, string curr) {
        int n = sequence.size();
        int m = curr.size();
        
        for (int i = 0; i <= n - m; i++) {
            int count = 0;
            for (int j = 0; j < m; j++) {
                if (sequence[i + j] == curr[j]) {
                    count++;
                }
            }
            if (count == curr.size()) return true;
        }
        return false;
    }
    int helper(string sequence, string word, string curr, int k) {
        if(substring(sequence,curr) == false) {
            return k;
        }
        else return helper(sequence, word, curr + word, k+1);
    }
    int maxRepeating(string sequence, string word) {
        return helper(sequence, word, word, 0);
    }
};