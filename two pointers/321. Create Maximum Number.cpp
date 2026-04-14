//321. Create Maximum Number
//C++
//https://leetcode.com/problems/create-maximum-number/description/?envType=problem-list-v2&envId=two-pointers

class Solution {
public:
    vector<int> merge_into_greater(vector<int>& temp1, vector<int>& temp2) {
        int a = 0;
        int b = 0;
        vector<int> ans;
        while(a < temp1.size() && b < temp2.size()) {
            if(temp1[a] == temp2[b]) {
                int x = a, y = b;
                while(x < temp1.size() && y < temp2.size() && temp1[x] == temp2[y]) {
                    x++;
                    y++;
                }
                if((y >= temp2.size())) {ans.push_back(temp1[a]); a++;}
                else if(x >= temp1.size()) {ans.push_back(temp2[b]); b++;}
                else if(temp1[x] > temp2[y]) {ans.push_back(temp1[a]); a++;}
                else {ans.push_back(temp2[b]); b++;}
            }
            else if(temp1[a] > temp2[b]) {ans.push_back(temp1[a]); a++;}
            else {ans.push_back(temp2[b]); b++;}
        }
        while(a < temp1.size()) {
            ans.push_back(temp1[a]);
            a++;
        }
        while(b < temp2.size()) {
            ans.push_back(temp2[b]);
            b++;
        }
        return ans;
    }

    vector<int> best_sequence_nums(vector<int>& nums, int n) {
        if(nums.size() == 0 || n == 0) return {};
        vector<int> ans(n, 0);
        stack<int> s;
        s.push(nums[0]);
        for(int i = 1; i < nums.size(); i++) {
            while(s.empty() == false && nums[i] > s.top() && (nums.size() - i + (s.size() - 1)) >= n) {
                s.pop();
            }
            s.push(nums[i]);
        }
        while(s.size() > n) {
            s.pop();
        }
        for(int i = n-1; i >= 0; i--) {
            ans[i] = s.top();
            s.pop();
        }
        return ans;
    }


    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> ans = {};
        for(int pick = 0; pick <= nums1.size(); pick++) {
            int pick_from_one = pick;
            int pick_from_two = k - pick;
            if(pick_from_one > nums1.size() || pick_from_two > nums2.size()) continue;

            vector<int> t1 = best_sequence_nums(nums1, pick_from_one);
            vector<int> t2 = best_sequence_nums(nums2, pick_from_two);

            vector<int> res = merge_into_greater(t1, t2);

            ans = max(ans, res);
        }
        return ans;
    }
};