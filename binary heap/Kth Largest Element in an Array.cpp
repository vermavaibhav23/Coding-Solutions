//Kth Largest Element in an Array
//Compiler - C++
//https://leetcode.com/problems/kth-largest-element-in-an-array/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        for(int i=0; i<k-1; i++) {
            pq.pop();
        }
        return pq.top();
    }
};