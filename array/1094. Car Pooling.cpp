//1094. Car Pooling
//C++
//https://leetcode.com/problems/car-pooling/

class Solution {
public:
    static bool myComparator(vector<int> a, vector<int> b) {
        if(a[1] < b[1]) return true;
        else return false;
    }
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(), trips.end(), myComparator);
        if(trips.size() == 1 ) {
            if(trips[0][0] > capacity) return false;
            else return true;
        }
        int people = 0;
        int i = 0;
        int checkpoint = 0;
        unordered_map<int, int> end;
        while(i < trips.size() && checkpoint <= 1000) {
            if(end.count(checkpoint)) people -= end[checkpoint];
            while(i < trips.size() && trips[i][1] == checkpoint) {
                people += trips[i][0];
                if(people > capacity) return false;
                if(end.count(trips[i][2])) end[trips[i][2]] += trips[i][0];
                else end[trips[i][2]] = trips[i][0];
                i++;
            }
            checkpoint++;
        }
        return true;
    }
};