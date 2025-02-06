//https://www.interviewbit.com/problems/implement-power-function/
//compiler : C++17 (Gcc - 9.2)
//Implement Power Function

int Solution::pow(int x, int n, int d) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    // Edge case: 0^0 is conventionally treated as 1

    x = (x % d + d) % d; 
    if (n == 0 || x == 0) {
        return (1%d);
    }
    if (n == 1) {
        return x%d;
    }
    if (n % 2 == 0) {
        return ( (long long)( pow(x,n/2,d ) * (long long) ( pow(x,n/2,d)) ) %d );
    }
    else return ( (long long)(pow(x,n/2,d) * (long long)(pow(x,n/2,d ))) %d * x %d ) %d ;
}