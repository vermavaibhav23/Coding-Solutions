//869. Reordered Power of 2
//Compiler - C++
//https://leetcode.com/problems/reordered-power-of-2/

class Solution {
public:
    bool reorderedPowerOf2(int n) {
        int x = n;
        int window = 0;
        unordered_map<int, int>m;
        while(x > 0) {
            m[ x % 10 ]++;
            window++;
            x = x/10;
        }
        long long expo = 1;
        while(true) {
            unordered_map<int, int>freq; 
            long long temp = expo;
            int expo_window = 0;
            while(temp > 0) {
                freq[ temp % 10 ]++;
                expo_window++;
                if(expo_window > window) return false;
                temp = temp/10;
            }
            if(freq == m) return true;
            expo = expo * 2;
        }
        return false;
    }
};