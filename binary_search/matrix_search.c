//https://www.interviewbit.com/problems/matrix-search/
//compiler : C
//Matrix Search
/**
 * @input A : 2D integer array 
 * @input n11 : Integer array's ( A ) rows
 * @input n12 : Integer array's ( A ) columns
 * @input B : Integer
 * 
 * @Output Integer
 */
int searchMatrix(int** A, int n11, int n12, int B) {
    int row = n11;
    int column = n12;
    int save = 0;
    int start = 0;
    int end = row - 1;
    int mid=0;
    // printf("%d %d %d, %d\n", start, end, row, column);
    
    while (start <= end) {
        mid = (start + end)/2;
        start_of_mid_row = A[mid][0];
        // printf("mid: %d", mid);
        if (A[mid][0] <= B) {
            // printf("a[mid] %d, a[mid+1] %d\n", A[mid][0], A[mid+2]);
            if ( (mid+1) < row ) {
                start_of_next_row = A[mid + 1][0];
                if start_
                start = mid + 1;
            }
            else { 
                save = mid;
                break;
            }
        }
        else {
            end = mid - 1;
        }
    }
    save = mid;
    // return save;
    // printf ("%d", save);
    start=0;
    end= column - 1;
    mid=(start+end)/2;
    while (start <= end) {
        mid = ( start + end)/2;
        if (A[save][mid] == B) {
            return 1;
        }
        if (A[save][mid] < B) {
            start = mid +1;
        }
        else {
            end = mid -1;
        }
    }
    //printf (" %d", mid);
    return 0;
}
