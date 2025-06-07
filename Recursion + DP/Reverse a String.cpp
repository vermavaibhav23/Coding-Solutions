//Reverse a String
//Compiler - C++
//https://www.geeksforgeeks.org/problems/reverse-a-string/1

class Solution {
  public:
    string reverseString(const string& s) {
        // code here
        if(s.size() == 0){
            return{};
        }
        return reverseString(s.substr(1)) + s[0];
    }
};
