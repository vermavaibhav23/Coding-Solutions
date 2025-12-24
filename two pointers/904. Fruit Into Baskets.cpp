//904. Fruit Into Baskets
//Compiler - C++
//https://leetcode.com/problems/fruit-into-baskets/description/

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        if(fruits.size() <= 2) return fruits.size();
        unordered_map<int,int>freq;
        int l = 0;
        int r = 0;
        int ans = 0;
        while(r < fruits.size()) {
            freq[fruits[r]]++;
            while(freq.size() > 2) {
                freq[fruits[l]]--;
                if(freq[fruits[l]] == 0) freq.erase(fruits[l]);
                l++;
            }
            ans = max(ans, r-l+1);
            r++;
        }
        return ans;
    }
};