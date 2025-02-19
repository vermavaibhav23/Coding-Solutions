LeetCode - Check If a Word Occurs As a Prefix of Any Word in a Sentence
Compiler - C++
https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/?envType=problem-list-v2&envId=two-pointers

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int ans = -1;
        int ssize = searchWord.size();
        string s;
        int j = 0;
        int count = 1;
        for(int i=0; i< sentence.size(); i++) {
            if(sentence[i] == ' '){
                count++;
            }
            if( searchWord[j] == sentence[i] && ( i==0 || sentence [i-1] == ' ') ){
                s = sentence.substr(i,ssize);
                if (s == searchWord ) {
                    return count;
                }
            }
        }
        return ans;
    }
};