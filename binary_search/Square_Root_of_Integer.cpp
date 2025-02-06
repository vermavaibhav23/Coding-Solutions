//https://www.interviewbit.com/problems/square-root-of-integer/
//compiler : C++
//Square Root of Integer
int Solution::sqrt(int A) {
    int start = 0;
    long long end = A;
    long long B = end;
    long long mid = end/2;
    int ans = 0;
    
    while (start <= end) {
        mid = (end+start)/2;
        if ( mid*mid > B) {
            end = mid - 1;
            ans = mid;
        }
        else if ( mid*mid < B) {
            start = mid + 1;
            ans =  mid;
        }
        else {
            ans = mid;
            break;
        }
    }
    if ( ans*ans > B) {
        ans--;
        return ans;
    }
    return ans;
}
