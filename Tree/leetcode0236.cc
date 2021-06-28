/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 // 时间复杂度O(n)，空间复杂度O(n)
class Solution {
public:
    bool findNode(TreeNode* root, TreeNode* target) {
        if(root==nullptr) return false;
        if(root==target) return true;
        return findNode(root->left, target) || findNode(root->right, target);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr) return nullptr;
        TreeNode* result = lowestCommonAncestor(root->left, p, q);
        if(result) return result;
        result = lowestCommonAncestor(root->right, p, q);
        if(result) return result;
        if(findNode(root, p)&&findNode(root, q)) return root;

        return nullptr;
    }
};