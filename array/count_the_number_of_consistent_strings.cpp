LeetCode - Count the Number of Consistent Strings
Compiler - C++
https://leetcode.com/problems/count-the-number-of-consistent-strings/description/?envType=problem-list-v2&envId=array

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        map <char , int> frequency;
        int Asize = allowed.size(), count = 0, w=0;
        int Wsize = words.size();

        for (int i=0; i<Asize; i++) {
        frequency[allowed[i]] ++ ;
        }

        for (int j=0; j<Wsize; j++) {
            w = 0;
            for (int z=0; z != words[j].size(); z++) {
                if (frequency.find(words[j][z]) == frequency.end()) {
                    w = 100;
                    break;
                }
            }
        if ( w != 100 ) {
            count ++;
        } 

        }
    return count;
    }
};