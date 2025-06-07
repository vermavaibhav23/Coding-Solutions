//Delete Mid of a Stack
//Compiler - C++
//https://www.geeksforgeeks.org/problems/delete-middle-element-of-a-stack/1

class Solution {
  public:
    void realdelete(stack<int>& s, int count, int pos){
        if(s.empty()) {
            return;
        }
        if(count == pos) {
            s.pop();
            return;
        }
        int top = s.top();
        s.pop();
        realdelete(s,count+1,pos);
        s.push(top);
    }
    void deleteMid(stack<int>& s) {
        int size_of_stack = s.size();
        int pos = ceil((size_of_stack +1)/2.0);
        realdelete(s,1,pos);
    }
};