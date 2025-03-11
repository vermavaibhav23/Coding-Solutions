//Finding 3-Digit Even Numbers
//Compiler - C++
//https://leetcode.com/problems/finding-3-digit-even-numbers/?envType=problem-list-v2&envId=sorting

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int>ans;
        map<int,int>f;
        for(int i=0; i<digits.size(); i++) {
            f[digits[i]]++;
        }

        for(int i=100; i<1000; i = i+2) {
            int count = 0;
            int a=i;
            map<int,int>temp;
            for(int j=0; j<3; j++) {
                temp[a%10]++;
                a = a/10;
            }
            for(auto it:temp) {
                if(f.find(it.first) != f.end()) {
                    if(f[it.first] < temp[it.first]) {
                        continue;
                    }
                    else count++;
                }
            }
            if(count == temp.size()) {
                ans.push_back(i);
            }
        }
    return ans;
    }
};