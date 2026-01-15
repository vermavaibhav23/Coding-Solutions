//151. Reverse Words in a String
//C++
//https://leetcode.com/problems/reverse-words-in-a-string/?envType=company&envId=microsoft&favoriteSlug=microsoft-all
class Solution {
public:
    string reverseWords(string s) {
        stack<string> store;
        string temp = "";
        for(int i = 0; i < s.size(); i++) {
            if(s[i] != ' ') temp = temp + s[i];
            else {
                if(temp != "") store.push(temp);
                temp = "";
            }
        }
        if (!temp.empty()) store.push(temp);
        string ans = "";
        while(store.empty() == false) {
            ans = ans + store.top() + " ";
            store.pop();
        }
        if(ans.size() > 0) ans.pop_back();
        return ans;
    }
};