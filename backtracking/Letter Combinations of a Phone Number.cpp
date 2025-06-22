//Letter Combinations of a Phone Number
//Compiler - C++
//https://leetcode.com/problems/letter-combinations-of-a-phone-number/?envType=problem-list-v2&envId=backtracking

class Solution {
public:
    void helper(vector<string>&mapping, string digits, int n, int curr, string letter, vector<string>&ans) {
        if(curr == n) {
            ans.push_back(letter);
            return;
        }
        string val = mapping[digits[curr] - '0'];
 
        for(int i = 0; i< val.size(); i++) {
            helper(mapping,digits,n, curr+1 , letter+val[i], ans);
        }
      
        return;
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty() || digits == "0" || digits == "1") {
            return {};
        }
        vector<string>mapping(10,"-1");
        vector<string>ans;
        string letter = "";
        mapping[2] = "abc";
        mapping[3] = "def";
        mapping[4] = "ghi";
        mapping[5] = "jkl";
        mapping[6] = "mno";
        mapping[7] = "pqrs";
        mapping[8] = "tuv";
        mapping[9] = "wxyz";
        helper(mapping, digits, digits.size(), 0, letter, ans);
        return ans;
    }
};