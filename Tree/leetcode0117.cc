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

// 递归法
class Solution1 {
public:
    Node* connect(Node* root) {
        if(root==nullptr) return root;
        if(root->left&&root->right) {
            root->left->next = root->right;
        }
        if(root->left!=nullptr&&root->right==nullptr) {
            root->left->next = getNext(root->next);
        }
        if(root->right) {
            root->right->next = getNext(root->next);
        }
        // 一定要注意先递归右子树，因为如果先递归左子树的话，
        // 左子树一直递归就会出现对于右半边树的某个节点，
        // 其上一层的root并没有和左半边树的root的next连起来的情况，
        // 从而导致该层的左半边的节点的next也找不到下一个节点。
        connect(root->right);
        connect(root->left);
        return root;
    }

    Node* getNext(Node* root) {
        if(root==nullptr) return root;
        if(root->left) return root->left;
        if(root->right) return root->right;
        if(root->next) return getNext(root->next);

        return nullptr;
    }
};


// 利用已经建立的next指针
class Solution {
public:
    void handle(Node* &last, Node* node, Node* &nextStart) { // last,nextStart需要使用引用来修改实参的实际值
        if(last) last->next = node;
        if(nextStart==nullptr) nextStart = node;
        last = node;
    }
    Node* connect(Node* root) {
        if(root==nullptr) return root;
        Node* start = root;
        while(start) {
            Node* last = nullptr, *nextStart = nullptr;
            Node* node = start;
            while(node) {
                if(node->left) {
                    handle(last, node->left, nextStart);
                }
                if(node->right) {
                    handle(last, node->right, nextStart);
                }
                node = node->next;
            }
            start = nextStart;
        }

        return root;
    }
};