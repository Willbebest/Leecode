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
class Solution1 {
public:
    void postorderTraversal(TreeNode* root, vector<int>& result) {
        if(root==nullptr) return;
        if(root->left) postorderTraversal(root->left, result);
        if(root->right) postorderTraversal(root->right, result);
        result.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        postorderTraversal(root, result);
        return result;
    }
};

class Solution2 {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> stk;
        TreeNode* node = root;
        TreeNode* pre = nullptr;
        while(stk.size()||node) {
            while(node) {               // 1.遍历到最左子节点
                stk.push(node);
                node = node->left;
            }
            node = stk.top(); stk.pop();
            if(node->right&&pre != node->right) { // 2.遍历最左子节点的右子树(右子树存在 && 未访问过)
                stk.push(node);
                node = node->right;
            } else {   // 没有右子树或右子树已经访问完
                result.push_back(node->val);
                pre=node;                   // 避免重复访问右子树
                node =nullptr;              // 避免重复访问左子树
            }
        }

        return result;
    }
};