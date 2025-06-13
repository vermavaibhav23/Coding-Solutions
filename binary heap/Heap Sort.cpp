//Heap Sort
//Compiler - C++
//https://www.geeksforgeeks.org/problems/heap-sort/1

// The functions should be written in a way that array become sorted
// in increasing order when heapSort() is called.

class Solution {
  public:
    void maxHeapify(vector<int>& arr, int size, int i) {
        int left = (2*i) + 1;
        int right = (2*i) + 2;
        int max = i;
        if(left<size && arr[left] > arr[max]) {
            max = left;
        }
        if(right<size && arr[right] > arr[max]) {
            max = right;
        }
        if( max != i) {
            int temp = arr[i];
            arr[i] = arr[max];
            arr[max] = temp;
            maxHeapify(arr, size, max);
        }
    }
    void buildHeap(vector<int>& arr) {
        int size = arr.size();
        for(int i = (size-2)/2; i>=0; i++) {
            maxHeapify(arr, size, i);
        }
    }
    void heapSort(vector<int>& arr) {
        buildHeap(arr);
        int size = arr.size();
        while(size>1) {
            int temp = arr[0];
            arr[0] = arr[size-1];
            arr[size-1] = temp;
            size--;
            maxHeapify(arr,size, 0);
        }
    }
};