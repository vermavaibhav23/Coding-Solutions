LeetCode - Distribute Candies
Compiler - C++
https://leetcode.com/problems/distribute-candies/?envType=problem-list-v2&envId=array

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
       map <int,int> m1;
       for (int i: candyType) {
            m1[i]++;
       }
       int size = candyType.size();
       int half = size/2;
       if (m1.size() >= half) {
            return half;
       }
       else if (m1.size() < half) {
            return m1.size();
       }
    return 0;
    }
};