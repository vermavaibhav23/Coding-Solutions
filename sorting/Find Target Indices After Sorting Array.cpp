//Find Target Indices After Sorting Array
//Compiler - C++
//https://leetcode.com/problems/find-target-indices-after-sorting-array/?envType=problem-list-v2&envId=sorting

class Solution {
public:
    vector<int> sort(vector<int> nums) {
        int temp;
        for (int i = 0; i < nums.size() - 1; i++) {
            int min = i;
            for (int j = i + 1; j < nums.size(); j++) { 
                if (nums[j] < nums[min]) {
                    min = j;
                }
            }
       
            if (min != i) {
                temp = nums[i];
                nums[i] = nums[min];
                nums[min] = temp;
            }
        }
        return nums;
    }


    vector<int> targetIndices(vector<int>& nums, int target) {
        nums = sort(nums);
        vector<int>v;
        int front = 0;
        int back = nums.size() -1;
        int mid;
        int firstoccurence = -1,lastoccurence=-1;
        while(front <= back) {
            mid = (front+back)/2;
            if(nums[mid] == target) {
                firstoccurence=mid;
                back = mid-1;
            }
            else if(nums[mid] > target) {
                back = mid-1;
            }
            else front = mid+1;
        }

        if (firstoccurence == -1) return v;

        front = 0;
        back = nums.size() -1;

        while(front <= back) {
            mid = (front+back)/2;
            if(nums[mid] == target) {
                lastoccurence = mid;
                front = mid+1;
            }
            else if(nums[mid] > target) {
                back = mid-1;
            }
            else front = mid+1;
        }
        cout<<firstoccurence<<" and "<<lastoccurence<<endl;
        for(int i= firstoccurence; i<=lastoccurence; i++) {
            v.push_back(i);
        }
        return v;
    }
};