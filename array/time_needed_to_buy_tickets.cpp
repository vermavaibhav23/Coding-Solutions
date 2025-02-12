LeetCode - Time Needed to Buy Tickets
Compiler - C++
https://leetcode.com/problems/time-needed-to-buy-tickets/description/?envType=problem-list-v2&envId=array

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time=0,max=0;
        int size = tickets.size();
        for (int j=0; tickets[k] >0; j++) {
            for (int z=0; z<size; z++) {
                if (tickets[z] > 0) {
                    tickets[z] --;
                    time++;
                }
                if (tickets[k] == 0) {
                    break;
                }
            }
        }
    return time;
    }
};