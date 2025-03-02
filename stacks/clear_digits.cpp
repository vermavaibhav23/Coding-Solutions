//Clear Digits
//Compiler - C++
//https://leetcode.com/problems/clear-digits/description/?envType=problem-list-v2&envId=stack

class Solution {
public:
    string clearDigits(string s) {
        vector<char>result;
        set<char> s1 = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
        for (int i=0; i< s.size(); i++) {
            if (s1.find(s[i]) == s1.end()) {
                result.push_back(s[i]);
            }
            else if (s1.find(s[i]) != s1.end() && result.size() > 0) {
                result.pop_back();
            }
        }
    return string(result.begin(), result.end());
    }
};