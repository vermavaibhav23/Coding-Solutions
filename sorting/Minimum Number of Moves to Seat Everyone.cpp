//Minimum Number of Moves to Seat Everyone
//Compiler - C++
//https://leetcode.com/problems/minimum-number-of-moves-to-seat-everyone/description/?envType=problem-list-v2&envId=sorting

class Solution {
public:
    vector<int> sorting (vector<int>nums) {
        int temp;
        for(int i=0; nums.size()>1 && i<= nums.size()-2; i++) {
            int min = i;
            for(int j=i; j< nums.size(); j++) {
                if (nums[j] < nums[min]) {
                    min = j;
                }
            }
            temp = nums[i];
            nums[i] = nums[min];
            nums[min] = temp;
        }
        return nums;
    }

    int mode(int x) {
        if(x < 0) {
            x = x* (-1);
        }
        return x;
    }

    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        seats = sorting(seats);
        students = sorting(students);
        int count = 0;
        int sum = 0;
        for(int i=0; i<seats.size(); i++) {
            cout<<i<<" : "<<seats[i]<<" and "<<students[i]<<endl;
            sum = sum + mode(students[i] - seats[i]);
        }
    return sum;
    }
};