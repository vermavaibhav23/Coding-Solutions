//https://www.interviewbit.com/problems/rotated-array/
// compiler: C++17
//Rotated Array

int Solution::findMin(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int c = 0;
    int f = 0;
    int b = A.size() - 1;
    int m = (f+b)/2;
    while ((f+1) < b) {
        m = (f+b)/2;
        if (A[f] > A[m]) {
            b = m;
        }
        else {
            f = m;
        }
    }
    if (A[b] > A[f]) {
        return A[0];
    }
    return A[b];    
}
