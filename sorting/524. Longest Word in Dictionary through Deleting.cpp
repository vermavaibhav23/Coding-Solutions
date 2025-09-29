//524. Longest Word in Dictionary through Deleting
//Compiler - C++
//https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/

class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string chosen_word = "";
        for(auto it: dictionary) {
            string temp = it;
            int a = 0;
            int b = 0;
            while(a < s.size() && b < temp.size()) {
                if(s[a] == temp[b]) {
                    a++;
                    b++;
                }
                else a++;
            }
            if(b == temp.size() && temp.size() >= chosen_word.size()) {
                if(temp.size() == chosen_word.size()) {
                    if(temp < chosen_word) {
                        chosen_word = temp;
                    }
                }
                else chosen_word = temp;
            }
        }
        return chosen_word;
    }
};