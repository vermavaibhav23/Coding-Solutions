//Largest Element in Array
//Compiler - C++
//https://www.geeksforgeeks.org/problems/largest-element-in-array4009/1

class Solution {
  public:
    int largestHelper(vector<int> &arr, int n) {
        if(n == 1) {
            return arr[0];
        }
        return max(arr[n-1], largestHelper(arr,n-1));
    }
    int largest(vector<int>& arr) {
        return largestHelper(arr, arr.size());
    }
};
