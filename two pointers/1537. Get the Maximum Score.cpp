//1537. Get the Maximum Score
//C++
//https://leetcode.com/problems/get-the-maximum-score/description/?envType=problem-list-v2&envId=two-pointers

class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        long long sum1 = 0, sum2 = 0;
        long long sum = 0;
        while(i < nums1.size() && j < nums2.size()) {
            if(nums1[i] < nums2[j]) {
                sum1 = sum1 + nums1[i];
                i++;
            }
            else if(nums1[i] > nums2[j]) {
                sum2 = sum2 + nums2[j];
                j++;
            }
            else {
                sum = sum + max(sum1, sum2) + nums1[i];
                sum1 = 0;
                sum2 = 0;
                i++;
                j++;
            }
        }
        while(i < nums1.size()) {
            sum1 = sum1 + nums1[i];
            i++;
        }
        while(j < nums2.size()) {
            sum2 = sum2 + nums2[j];
            j++;
        }
        sum = sum + max(sum1, sum2);
        return sum % 1000000007;
    }
};