//Power Of Numbers
//Compiler - C++


class Solution {
  public:
    long long powerr(int n, int power) {
        int MOD = 1e9+7;
        if(power == 0) {
            return 1;
        }
        if(power % 2 == 0) {
            long long ans = powerr(n, power/2);
            return (ans%MOD * ans%MOD)%MOD;
        }
        else{
            long long ans = powerr(n, (power-1)/2);
            return (ans%MOD * ans%MOD * n%MOD)%MOD;
        }
    }
};