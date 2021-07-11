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
    void preorderTraversal(TreeNode* root, vector<int>& result) {
        if(root == nullptr) return;
        result.push_back(root->val);              // 根节点
        preorderTraversal(root->left, result);    // 右子树
        preorderTraversal(root->right, result);   // 左子树
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        preorderTraversal(root, result);
        return result;
    }
};

// 迭代法
class Solution2 {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root == nullptr) return result;
        stack<TreeNode*> stk;
        stk.push(root);
        while(stk.size()) {
            TreeNode* node = stk.top(); stk.pop();
            result.push_back(node->val);
            if(node->right) stk.push(node->right);
            if(node->left) stk.push(node->left);
        }

        return result;
    }
};