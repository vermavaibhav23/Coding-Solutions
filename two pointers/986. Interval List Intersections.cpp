//986. Interval List Intersections
//Compiler - C++
//https://leetcode.com/problems/interval-list-intersections/

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int a = 0;
        int b = 0;
        vector<vector<int>>ans;
        while(a < firstList.size() && b < secondList.size()){
            int p = firstList[a][0];
            int q = firstList[a][1];
            int x = secondList[b][0];
            int y = secondList[b][1];
            if( (x <= q) && (y >= p) ) {  // they will overlap
                int first = max(p,x);
                int second = min(q,y);
                ans.push_back({first, second});
            } 
            if(q > y) {
                b++;
            }
            else {
                a++;
            }
        }
        return ans;
    }
};