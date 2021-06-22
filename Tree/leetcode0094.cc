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
class Solution1 {
public:
    void inorderTraversal(TreeNode*root, vector<int>& result) {
        if(root==nullptr) return;
        if(root->left) inorderTraversal(root->left, result);   // 左子树
        result.push_back(root->val);						   // 根节点
        if(root->right) inorderTraversal(root->right, result); // 右子树
    }  
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorderTraversal(root, result);
        return result;
    }
};


class Solution2 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> stk;
        TreeNode* node = root;
        while(stk.size() || node) {
            while(node) {
                stk.push(node);
                node = node->left;
            }
            node = stk.top(); stk.pop();
            result.push_back(node->val);
            
            node = node->right;
        }

        return result;
    }
};