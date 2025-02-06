//https://www.interviewbit.com/problems/search-for-a-range/
//compiler : C++
//Search for a Range
vector<int> Solution::searchRange(const vector<int> &A, int B) {
    vector<int> arr = {-1,-1};
    int start=0;
    int end= A.size() - 1;
    int mid = -1;
    int ans = -1;
    while (start<=end) {
        mid = (start + end)/2;
        if (A[mid] == B) {
            end = mid - 1;
            ans = mid;
        }
        else if (A[mid] > B) {
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }
    arr[0] = ans;
    // cout<<ans<<endl;;
    
    
    ans = -1;
    start=0;
    end= A.size() - 1;
    mid = -1;
    while (start <= end) {
        mid = (start + end)/2;
        if (A[mid] == B) {
            start = mid + 1;
            ans = mid;
        }
        else if (A[mid] > B) {
            end = mid - 1;
        }
        else  {
            start = mid + 1;
        }
    }
    arr[1] = ans;
    // cout<<ans<<endl;;
return arr;
}
