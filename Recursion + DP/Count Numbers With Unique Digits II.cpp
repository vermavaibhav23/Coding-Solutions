//Count Numbers With Unique Digits II
//Compiler - C++
//https://leetcode.com/problems/count-numbers-with-unique-digits-ii/?envType=problem-list-v2&envId=dynamic-programming

class Solution {
public:
    bool unique(int x) {
        set<int>s;
        int count = 0;
        while (x>0) {
            count++;
            s.insert(x % 10);
            x= x/10;
        }
        if(count == s.size()) {
            return true;
        }
        return false;
    }
    int numberCount(int a, int b) {
        if(b < a) {
            return 0;
        }
        if( unique(b) ) {
            return 1+numberCount(a,b-1);
        }
        else return numberCount(a, b-1);
    }
};