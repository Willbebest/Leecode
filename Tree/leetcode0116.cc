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

class Solution1 {
public:
    Node* connect(Node* root) {
        if(root==nullptr) return root;
        queue<Node*> queNode;
        queNode.push(root);
        while(queNode.size()) {
            size_t size = queNode.size();
            for(size_t i = 0; i<size; i++) {
                Node* node = queNode.front(); queNode.pop();
                if(i<size-1) node->next = queNode.front();  // 注意 size
                if(node->left) queNode.push(node->left);
                if(node->right) queNode.push(node->right); 
            }
        }

        return root;
    }
};

// 非递归：利用父节点已经连接完成
class Solution3 {
public:
    Node* connect(Node* root) {
        if(root==NULL) return root;
        Node* start = root;
        while(start->left) {
            Node* node = start;
            while(node) {
                node->left->next=node->right;
                if(node->next) {
                    node->right->next = node->next->left;
                }
                node= node->next;
            }
            start = start->left;
        }
        return root;
    }
};