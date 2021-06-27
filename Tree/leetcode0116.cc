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
    void connect(Node* lroot, Node* rroot) {
        if(lroot==NULL||lroot->next == rroot) return; // 避免重复递归
        lroot->next = rroot;
        connect(lroot->left, lroot->right);
        connect(rroot->left, rroot->right);
        connect(lroot->right, rroot->left);
    }
    Node* connect(Node* root) {
        if(root!=NULL)
            connect(root->left, root->right);
        return root;
    }
};