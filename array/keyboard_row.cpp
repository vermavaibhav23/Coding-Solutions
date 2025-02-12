LeetCode - Keyboard Row
Compiler - C++
https://leetcode.com/problems/keyboard-row/description/?envType=problem-list-v2&envId=array

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string>v;
        int row1=0, row2=0, row3=0;
        set<char>r1 = {'q','w','e','r','t','y','u','i','o','p','Q','W','E','R','T','Y','U','I','O','P'};
        set<char>r2 = {'a','s','d','f','g','h','j','k','l','A','S','D','F','G','H','J','K','L'};
        set<char>r3 = {'z','x','c','v','b','n','m','Z','X','C','V','B','N','M'};
        for (int i=0; i< words.size(); i++) {
            row1=0;
            row2=0;
            row3=0;
            for (int j=0; j< words[i].size(); j++) {
                if (r1.find(words[i][j]) != r1.end()) {
                    row1 = 1;
                }
                else if (r2.find(words[i][j]) != r2.end()) {
                    row2 = 1;
                }
                else if (r3.find(words[i][j]) != r3.end()) {
                    row3 = 1;
                }
            }
            cout<<row1<<row2<<row3<<endl;
            if ((row1 + row2 + row3) == 1) {
                v.push_back(words[i]);
            }
        }
    return v;
    }
};