//Find X-Sum of All K-Long Subarrays I
//Compiler - C++
//https://leetcode.com/problems/find-x-sum-of-all-k-long-subarrays-i/?envType=problem-list-v2&envId=sliding-window

class Solution {
public:
    map<int,int> frequency (vector<int>v) {
        map<int,int>f;
        for(int i=0; i<v.size(); i++) {
            f[v[i]]++;
        }
        return f;
    }

    int top_element(map<int,int>&f) {
        int max = 0;
        int key = 0;
        int occ=0;
        for(auto it: f) {
            if (max == it.second) {
                if(key < it.first){
                    key = it.first;
                }
            }
            else if(it.second > max) {
                max = it.second;
                key = it.first;
            }
        }
        //cout<<key<<endl;
        int a = key * f[key];
        f.erase(key);
        return a;
    }

    int sum_of_all(vector<int>v) {
        int sum =0;
        for(int i=0; i< v.size(); i++) {
            sum = sum + v[i];
        }
        return sum;
    }

    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int>ans;
        
        for(int i=0; (i+k) <= nums.size(); i++) {
            vector<int>sub(nums.begin() + i, nums.begin() + i + k);
            map<int,int>f = frequency(sub);
            if(f.size() < x) {
                ans.push_back(sum_of_all(sub));
                continue;
            }
            int sum = 0;
            for(int a=x; a>0; a--) {
                sum = sum + top_element(f);
            }
            ans.push_back(sum);
        }
        return ans;
    }
};