//Populating Next Right Pointers in Each Node
//Compiler - C++
//https://leetcode.com/problems/populating-next-right-pointers-in-each-node/?envType=problem-list-v2&envId=binary-tree


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
        Node* node = q.front();
        if(node == NULL) {
            return root;
        }
        while(!q.empty()) {
            int size = q.size();
            for(int i=0; i<size; i++) {
                node = q.front();
                q.pop();
                if(node->left != NULL) {
                    q.push(node->left);
                }
                if(node->right != NULL) {
                    q.push(node->right);
                }
                node->next = q.front();
            }
            node->next = NULL;
        }
        return root;
    }
};