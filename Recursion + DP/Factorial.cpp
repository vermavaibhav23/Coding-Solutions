//Factorial
//Compiler - C++
//https://www.geeksforgeeks.org/problems/factorial5739/1

class Solution {
  public:
    long long factorial(int n) {
        if(n<=1) {
            return 1;
        }
        return n * factorial(n-1);
    }
};