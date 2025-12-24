//1456. Maximum Number of Vowels in a Substring of Given Length
//Compiler - C++
//https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/

class Solution {
public:
    int maxVowels(string s, int k) {
        int r = 0;
        int vowel = 0;
        if(k == 0) return 0;
        while(r < k) {
            if(s[r] == 'a' || s[r] == 'e' || s[r] == 'i' || s[r] == 'o' || s[r] == 'u') {
                vowel++;
            }
            r++;
        }
        if(k == s.size()) return vowel;
        int l = 0;
        int ans = max(0, vowel);
        while(r < s.size()) {
            int window = r - l + 1;
            
            if(s[l] == 'a' || s[l] == 'e' || s[l] == 'i' || s[l] == 'o' || s[l] == 'u') {
                vowel--;
            }
            l++;
            if(s[r] == 'a' || s[r] == 'e' || s[r] == 'i' || s[r] == 'o' || s[r] == 'u') {
                vowel++;
            }
            ans = max(ans, vowel);
            r++;
        }
        return ans;
    }
};