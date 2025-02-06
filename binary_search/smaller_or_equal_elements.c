//https://www.interviewbit.com/problems/smaller-or-equal-elements/
//compiler : C
//Smaller or equal elements

/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * @input B : Integer
 * 
 * @Output Integer
 */
int solve(int* A, int n1, int B) {
    int ans = 0;
    int f = 0;
    int b = n1 - 1;
    int m = (f+b)/2;
    
    while(A[f] <= B) {
        m = (f+b)/2;
        if (A[m] > B){
            b = m-1;
        }
        else if (A[m] <= B){
            ans = ans + ((m+1) - f);
            f = m+1;
        }
    }
    return ans;
}

