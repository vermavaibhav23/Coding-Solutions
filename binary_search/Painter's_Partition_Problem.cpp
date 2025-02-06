//https://www.interviewbit.com/problems/painters-partition-problem/
//compiler : C++
//Painter's Partition Problem
int Solution::paint(int A, int B, vector<int> &arr) {
    int sum = 0;
    int max = 0;
    for (int i=0; i< arr.size(); i++) {
        sum = sum + arr[i];
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    if (A >= arr.size()) {
        return (max * B)%10000003;
    }
    int start = max;
    int end = sum;
    int mid = (start + end)/2;
    int painters = 1;
    long long add = 0;
    long long ans = 0;
    while (start <= end){
        mid = (start + end)/2;
        painters = 1;
        add = 0;
        for (int j = 0; j< arr.size(); j++) {
            add = add + arr[j];
            if (arr[j] > mid) {
                start = mid + 1;
                continue;
            }
            if (add > mid){
                add = 0;
                painters++ ;
                j--;
            }
        }
        if (painters <= A) {
            ans = mid;
            end = mid - 1;
        }
        else if (painters > A) {
            start = mid + 1;
        }
    }
    return (ans * B)%10000003;
}

