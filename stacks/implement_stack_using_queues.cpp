//Implement Stack using Queues
//Compiler - C++
//https://leetcode.com/problems/implement-stack-using-queues/?envType=problem-list-v2&envId=stack

class MyStack {
public:
queue <int> input;
queue <int> output;
int a=0;
    MyStack() {  
    }
    void push(int x) {
        if (output.empty()) {
            input.push(x);
        }
        else {
            output.push(x);
        }
    }
    int pop() {
        if (output.empty()) {
            int x;
            while (input.size() > 1) {
                x = input.front();
                input.pop();
                output.push(x);
            }
        int z = input.front();
        input.pop();
        return z;
        }
        else if (input.empty()) {
            int y;
            while (output.size() > 1) {
                y = output.front();
                output.pop();
                input.push(y);
            }
        int a = output.front();
        output.pop();
        return a;
        }
    return 0;
    }
    
    int top() {
        if (input.empty()) {
            return output.back();
        }
        return input.back();
    }
    
    bool empty() {
        if (input.empty() && output.empty()) {
            return true;
        }
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */