//Generate Parentheses
//Compiler - C++
//https://leetcode.com/problems/generate-parentheses/?envType=problem-list-v2&envId=dynamic-programming

class Solution {
public:
    bool isvalid(string test) {
        stack<char>s;
        if(test[0] == ')' || test[test.size() - 1] == '(') {
            return false;
        }
        for(int i=0; i<test.size(); i++) {
            if(test[i] == '(') {
                s.push(test[i]);
            }
            else if(test[i] == ')') {
                if(s.empty()) {
                    return false;
                }
                else s.pop();
            }
        }
        if(s.empty()) {
            return true;
        }
        return false;
    }
    void helper(vector<string>&ans, int n, string s, int open, int close) {
        if (s.size() == 2 * n && isvalid(s)) {
            ans.push_back(s);
            return;
        }
        if(open < n) {
            helper(ans, n, s+"(", open+1, close);
        }
        if(open> close) {
            helper(ans, n, s+")", open, close+1);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string s = "";
        helper(ans, n, s, 0, 0);
        return ans;
    }
};