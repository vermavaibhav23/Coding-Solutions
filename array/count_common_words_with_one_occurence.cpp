LeetCode - Count Common Words With One Occurrence
Compiler - C++
https://leetcode.com/problems/count-common-words-with-one-occurrence/description/?envType=problem-list-v2&envId=array

class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
       map<string,int>m1,m2;
       for (int i=0; i< words1.size(); i++) {
            m1[words1[i]]++;
       } 
       for (int i=0; i< words2.size(); i++) {
            m2[words2[i]]++;
       }
       int count = 0;
       for (auto it:m1) {
            if(m2.find(it.first) != m2.end() && it.second == 1 && m2[it.first] == 1) {
                cout<<it.first<<" "<<it.second<<endl;
                count++;
            }
       }
    return count;
    }
};