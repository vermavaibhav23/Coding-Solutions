//https://www.interviewbit.com/problems/count-element-occurence/
// compiler: C++17
//Count Element Occurence


int Solution::findCount(const vector<int> &A, int B) {
    int n1 = A.size(); 
    int first = 0;  
    int last = n1-1; 
    int mid = (first + last)/2; //mid = 5
    int count1 = 0;
    int ans = -1;
    int ans2 = 0;
    while (first <= last){
        mid = (first + last)/2;
        if (A[mid] > B){
            last = mid - 1;
        }
        else if (A[mid] < B){
            first = mid + 1;
        }
        if (A[mid] == B){
            ans = mid;
            last = mid - 1;
        }
    }
    
    count1 = ans;
    
    
    first = 0;
    last = n1-1; 
    ans = -1;
    while (first <= last){ // 
        mid = (first + last)/2;
        if (A[mid] > B){
            last = mid - 1;
        }
        else if (A[mid] < B){
            first = mid + 1;
        }
        if (A[mid] == B){
            ans = mid;
            first = mid + 1;
        }
    }
    if (ans != -1) {
        ans2 = ans - count1;
        ans2++;
        return ans2;
    }
    ans2 = ans - count1;
  
    
    return ans2;
}
