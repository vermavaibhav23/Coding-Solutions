//2517. Maximum Tastiness of Candy Basket
//Compiler - C++
//https://leetcode.com/problems/maximum-tastiness-of-candy-basket/

class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        int n = price.size();
        sort(price.begin(), price.end());
        if (k == 1) return price[k-1];
        int l = 0;
        int r = price[n-1] - price[0];
        if (k == 2) return r;
        int ans = 0;
        while(l <= r) {
            int mid = l + (r - l)/2;
            int number = 1;
            int first = price[0];
            for(int i = 1 ; i < price.size(); i++) {
                if(price[i] - first >= mid) {
                    first = price[i];
                    number++;
                }
            }
            if(number >= k) {
                cout<<mid<<", "<<number<<endl;
                ans = max(ans, mid);
                l = mid+1;
            }
            else r = mid-1;
        }
        return ans;
    }
};