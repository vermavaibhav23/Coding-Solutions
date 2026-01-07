//3075. Maximize Happiness of Selected Children
//C++
//https://leetcode.com/problems/maximize-happiness-of-selected-children/description/?envType=company&envId=microsoft&favoriteSlug=microsoft-thirty-days

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end());
        int cut = 0;
        long long ans = 0;
        int i = happiness.size() - 1;
        while(k > 0) {
            if(happiness[i] - cut > 0) ans += happiness[i] - cut;
            cut++;
            i--;
            k--;
        }
        return ans;
    }
};