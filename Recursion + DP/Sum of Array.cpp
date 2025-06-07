//Sum of Array
//Compiler - C++
//https://www.geeksforgeeks.org/problems/sum-of-array2326/1

// User function template for C++
class Solution {
  public:
    // Function to return sum of elements
    int recursive(vector<int>& arr, int n) {
        if(n == 0) {
            return arr[0];
        }
        return recursive(arr, n-1) + arr[n];
    }
    int arraySum(vector<int>& arr) {
        return recursive(arr, arr.size()-1);
    }
};