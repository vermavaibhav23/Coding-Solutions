//https://www.interviewbit.com/problems/sorted-insert-position/
//compiler : C++17 (Gcc -9.2)
//Sorted Insert Position
int Solution::searchInsert(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int start = 0;
    int end = A.size() - 1;
    int fixend = end;
    int mid = (start + end)/2;
    int ans = 0;
    
    while (start <= end) {
        mid = (start + end)/2;
        if (A[mid] <= B) {
            start = mid + 1;
            ans = mid;
        }
        else{
            end = mid - 1;
            ans = mid;
        }
        // else {
        //    ans = mid; 
        //    break;
        // } 
    }
    
    if (A[ans] < B) {
        ans++ ;
    }
    return ans;
}

