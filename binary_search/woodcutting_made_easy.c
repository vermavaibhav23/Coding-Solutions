//https://www.interviewbit.com/problems/woodcutting-made-easy/
//compiler : C
//WoodCutting Made Easy!

/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * @input B : Integer
 * 
 * @Output Integer
 */
int solve(int* A, int n1, int B) {
    int size = n1;
    int max = 0;
    int i = 0;
    for (i=0 ; i< size; i++) {
        if (A[i] > max) {
            max = A[i];
        }
    }
    int final_height = max;
    int final_ans = max;
    long long total_cutting = 0;
    int start = 0;
    int end = max;
    int mid = (start + end)/2;
    
    while (start <= end) {
        mid = (start + end)/2;
        total_cutting = 0;
        for (i = 0; i<size; i++) {
            if (A[i] > mid) {
                long long diff = A[i] - mid;
                total_cutting = total_cutting + diff;
            }  
        }
        if (total_cutting >= B) {
            start = mid + 1;
            final_ans = mid;
        }
        else if(total_cutting < B) {
            end = mid -1;
        }
    }
    return final_ans;
}
