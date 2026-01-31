//50. Pow(x, n)
//C++
//https://leetcode.com/problems/powx-n/?envType=company&envId=facebook&favoriteSlug=facebook-all

class Solution {
public:
    double helper(double x, int n) {
        if (n == 0) return 1;
        double half = helper(x, (int)n / 2);
        if (n % 2 == 0) return half * half;
        else return x * half * half;
    }

    double myPow(double x, int n) {
        long long N = n; 
        if (N < 0) {
            x = 1 / x;
            N = -1 * N;
        }
        return helper(x, N);
    }
};