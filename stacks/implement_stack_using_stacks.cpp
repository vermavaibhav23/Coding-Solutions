//Implement Stack using Stacks
//Compiler - C++
//https://leetcode.com/problems/implement-queue-using-stacks/description/?envType=problem-list-v2&envId=stack

class MyQueue {
public:
stack <int> input;
stack <int> output;
int peeke=0;
    MyQueue() {
        
    }
    
    void push(int x) {
        if (input.empty()) {
            peeke = x;
        }
        input.push(x);
    }
    
    int pop() {
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        int val = output.top();
        output.pop();
        return val;
    }
    
    int peek() {
        if (output.empty()) {
            return peeke;
        }
        return output.top();
    }
    
    bool empty() {
        if (input.empty() && output.empty()) {
            return true;
        }
        else return false;
        
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */