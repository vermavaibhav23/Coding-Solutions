//https://www.interviewbit.com/problems/rotated-sorted-array-search/
//compiler : C++17 (Gcc - 9.2)
//Rotated Sorted Array Search

int Solution::search(const vector<int> &A, int B) {
    int ans = -1;
    int start = 0;
    int end = A.size() - 1;
    int mid = (start + end)/2;
    int fstart , fend, fmid;
    
    
    while (start <= end) {
        mid = (start + end)/2;
        if (A[mid] == B){
            ans = mid; 
            return ans;
        }
        if (A[start] <= A[mid]) {
            if ( A[mid] > A[mid + 1] ) {
                if (B >= A[0]) {
                    fstart = 0;
                    fend = mid - 1;
                    break;
                }
                else {
                    fstart = mid + 1;
                    fend = A.size() - 1;
                    break;
                }
            }
            else {
                start = mid + 1;
            }
        }
        else {
            end = mid - 1;
        }
        
    }
    while (fstart <= fend) {
        fmid = (fstart + fend) / 2;
        if (A[fmid] == B) {
            ans = fmid;
            return ans;
        }
        else if (A[fmid] > B) {
            fend = fmid - 1; 
        }
        else if (A[fmid] < B) {
            fstart = fmid + 1; 
        }
    }
    return ans;
}
