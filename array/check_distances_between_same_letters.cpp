LeetCode - Check Distances Between Same Letters
Compiler - C++
https://leetcode.com/problems/check-distances-between-same-letters/?envType=problem-list-v2&envId=array

class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        map<char, int>m;
        int count=0;
        vector<int>v;
        for (int z=0; z< s.size(); z++) {
            if (m.find(s[z]) != m.end()){
                continue;
            }
            for (int i=z; ; i++) {
                if (s[i+1] != s[z]) {
                    count++;
                }
                else break;
            }
            m[s[z]] = count;
            count=0;
        }
        for (auto it:m) {
            cout<<it.first<<" "<<it.second<<endl;
        }
        int scount=0;
        char alpha;
        for (int i = 0, alpha = 'a'; i < 26; i++, alpha++) {
            if (m.find(alpha) != m.end() && distance[i] == m[alpha]) {
                scount++;
            }
        }
        if (scount == m.size()) {
            return true;
        }
    return false;
    }
};