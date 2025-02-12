LeetCode - Unique Morse Code Words
Compiler - C++
https://leetcode.com/problems/unique-morse-code-words/description/?envType=problem-list-v2&envId=array

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string arr[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."} ;
        map <char , string> mp;
        char letter = 'a';
        int count = 0, Wsize = words.size();
        vector<string> newWords(Wsize);
        string morse = "";
        for (int i=0; i<26; i++) {
            mp[letter] = arr[i];
            letter ++ ;
        }
        for (int j=0; j<Wsize; j++) {
            morse = "";
            for (int z=0; z < words[j].size() ; z++) {
                morse += mp[words[j][z]] ;
            }
            newWords[j] = morse;
        }
        map <string, int> frequency;
        for (int a=0; a<Wsize; a++) {
            frequency[newWords[a]]++;
        }
    return (frequency.size());
    }
};