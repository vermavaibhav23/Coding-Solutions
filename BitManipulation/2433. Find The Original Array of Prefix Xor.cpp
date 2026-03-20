//2433. Find The Original Array of Prefix Xor
//Compiler : C++
//https://leetcode.com/problems/find-the-original-array-of-prefix-xor/description/

class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> arr;
        arr.push_back(pref[0]);
        for(int i = 1; i < pref.size(); i++) {
            int sample = pref[i-1];
            int add = 0;
            int res = pref[i];
            int k = 0;

            while(k < 32) {
                int res_kbit = (res & 1<<k);
                if(res_kbit != 0) res_kbit = 1;

                int sam_kbit = (sample & 1<<k);
                if(sam_kbit != 0) sam_kbit = 1;

                if(res_kbit == 0) {
                    if(sam_kbit == 1) add = (add | 1<<k);
                }    
                else {
                    if(sam_kbit == 0) add = (add | 1<<k);
                }       

                k++;     
            }
            arr.push_back(add);
        }
        return arr;
    }
};