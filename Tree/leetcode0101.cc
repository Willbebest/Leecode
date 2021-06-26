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
class Solution {
public:
    bool isSymmetric(TreeNode* left_root, TreeNode* right_root) {
        if(left_root==nullptr&&right_root==nullptr) return true;   // 两棵树都没有节点
        if(left_root==nullptr|| right_root==nullptr || left_root->val!=right_root->val) return false;  // 至少有一个有节点
        
        return isSymmetric(left_root->left, right_root->right)&&
               isSymmetric(left_root->right,right_root->left);
    }

    bool isSymmetric(TreeNode* root) {
        if(root==nullptr) return true;
        return isSymmetric(root->left, root->right);
    }
};