LeetCode - Maximum Enemy Forts That Can Be Captured
Compiler - C++
https://leetcode.com/problems/maximum-enemy-forts-that-can-be-captured/?envType=problem-list-v2&envId=two-pointers

class Solution {
public:
    int captureForts(vector<int>& forts) {
        int count = -1;
        vector<int>ans;
        int lock = 0;
        int unlocker = 0;
        for(int i=0; i<forts.size(); i++){
            if(lock == 1 && (forts[i] == 1 || forts[i] == -1)) {
                lock = 0;
                if(forts[i] == -1 * unlocker) {
                    ans.push_back(count);
                }
                count = -1;
            }
            if(forts[i] == 1 || forts[i] == -1){
                lock = 1;
                unlocker = forts[i];
            }
            if (lock == 1){
                count++;
            }
        }
        int max=0;
        for(int i=0; i<ans.size(); i++){
            if(ans[i] > max){
                max = ans[i];
            }
        }
        return max;
    }
};