//1318. Minimum Flips to Make a OR b Equal to c
//Compiler : C++
//https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/

class Solution {
public:
    int helper(int a, int b, int c, int maxbits) {
        int ans = 0;
        while(maxbits > 0) {
            int alast = a % 2;
            int blast = b % 2;
            int clast = c % 2;

            if(clast == 0) ans += alast + blast;
            else {
                if(alast + blast == 0) ans++;
            }
            a = a/2;
            b = b/2;
            c = c/2;
            maxbits--;
        }
        return ans;
    }
    int minFlips(int a, int b, int c) {
        int abits = (int)log2(a)+1;
        int bbits = (int)log2(b)+1;
        int cbits = (int)log2(c)+1;
        int maxbits = max(abits, max(bbits,cbits));

        return helper(a,b,c,maxbits);
    }
};