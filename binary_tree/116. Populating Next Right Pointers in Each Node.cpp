//116. Populating Next Right Pointers in Each Node
//Compiler - C++
//https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*>q;
        q.push(root);
        if(root == NULL) return root;
        while(q.empty() == false) {
            int size = q.size();
            while(size > 0) {
                if(q.front()->left != NULL) q.push(q.front()->left);
                if(q.front()->right != NULL) q.push(q.front()->right);
                if(size == 1) {
                    q.front()->next = NULL;
                    q.pop();
                }
                else {
                    Node* curr = q.front();
                    q.pop();
                    curr->next = q.front();
                }
                size--;
            }
        }
        return root;
    }
};