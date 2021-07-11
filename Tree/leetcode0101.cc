/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// 递归法
class Solution {
public:
    bool isSymmetric(TreeNode* root1, TreeNode* root2) {
        if(root1==nullptr&&root2==nullptr) return true;
        if(root1==nullptr || root2==nullptr || root1->val!=root2->val) return false;
        return isSymmetric(root1->left, root2->right)&&isSymmetric(root1->right, root2->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr) return true;
        return isSymmetric(root->left, root->right);
    }
};

// 迭代法
class Solution1 {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr) return true;
        stack<TreeNode*> stk1;
        stack<TreeNode*> stk2;
        stk1.push(root->left);
        stk2.push(root->right);

        while(stk1.size()&&stk2.size()) {
            TreeNode* node1 = stk1.top(); stk1.pop();
            TreeNode* node2 = stk2.top(); stk2.pop();
            if(node1==nullptr&&node2==nullptr) continue;
            if(node1==nullptr || node2==nullptr || node1->val!=node2->val) return false;
            //空节点也push要进去
            stk1.push(node1->right);
            stk1.push(node1->left);

            stk2.push(node2->left);
            stk2.push(node2->right);
        }

        return true;
    }
};