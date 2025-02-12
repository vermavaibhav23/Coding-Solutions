LeetCode - Number of Students Unable to Eat Lunch
Compiler - C++
https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/description/?envType=problem-list-v2&envId=array

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int studentSize = students.size();
        int sandwichesSize = sandwiches.size();
        int studtemp, sandtemp, count=0;
        queue<int>student;
        queue<int>sandwich;
        for (int a = 0; a < studentSize; a++) {
        student.push(students[a]);
        }
        for (int b = 0; b < sandwichesSize; b++) {
        sandwich.push(sandwiches[b]);
        }
        for (int i=0; student.size() !=0 && count<studentSize; i++) {
            if (student.front() == sandwich.front()) {
                student.pop();
                sandwich.pop();
                count = 0;
            }
            else if (student.front() != sandwich.front()) {
                studtemp = student.front();
                student.pop();
                student.push(studtemp);
                count++ ;
            }
        }
    return student.size();
    }
};