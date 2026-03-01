//1513. Number of Substrings With Only 1s
//Compiler - C++
//https://leetcode.com/problems/number-of-substrings-with-only-1s/description/

class Solution {
public:
    int numSub(string s) {
        int MOD = 1000000007;
        int ans = 0;
        int cons_one = 0;
        for(int i = 0; i <= s.size(); i++) {
            cout<<i<<", "<<cons_one<<endl;
            if(i == s.size() || s[i] == '0') {
                while(cons_one > 0) {
                    ans = (ans + cons_one) % MOD;
                    cons_one--;
                }
            }
            else cons_one++;
        }
        return ans;
    }
};