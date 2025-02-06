//https://www.interviewbit.com/problems/search-in-bitonic-array/
//compiler : C++ 17
//Search in Bitonic Array!

int Solution::solve(vector<int> &A, int B) {
    int max = 0;
    int index = 0;
    
    int start = 0;
    int end = A.size() - 1;
    int mid = (start + end)/2;
    
    while (start <= end) {
        mid = (start + end)/2;
        if (A[mid] > A[mid + 1] && A[mid] > A[mid - 1]) {
            max = A[mid];
            index = mid;
            break;
        }
        else if (A[mid] > A[mid + 1] && A[mid] < A[mid - 1]) {
            end = mid - 1;
        }
        else start = mid + 1 ;  
    }
    start = 0;
    int findex = index;
    while (start <= index) {
        mid = (start + index)/2;
        if (A[mid] == B) {
            return mid;
        }
        if (A[mid] > B) {
            index = mid - 1;
        }
        else start = mid + 1;
    }
    start = A.size() - 1;
    end = findex + 1;
    while (start >= end) {
        mid = (start + end)/2;
        if (A[mid] == B) {
            return mid;
        }
        if (A[mid] > B) {
            end = mid + 1;
        }
        else start = mid - 1;
    }
    return -1;
}
