//Subset Sum Problem
//Compiler - C++
//https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

class Solution {
  public:
    bool helper(vector<int>& arr, int sum, int n) {
        if(sum == 0) {
            return true;
        }
        if(n <= 0) {
            return false;
        }
        if(arr[n-1] <= sum) {
            return ((helper(arr, sum - arr[n-1], n-1)) || helper(arr,sum,n-1));
        } 
        else return helper(arr,sum,n-1);
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        return helper(arr, sum, arr.size());
    }
};