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
// “自底向上” 的解决方案
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==nullptr) return 0;
        int left_height = maxDepth(root->left);
        int right_height = maxDepth(root->right);
        return max(left_height, right_height) + 1;
    }
};

// “自顶向下” 的解决方案
class Solution {
public:
    int result = 0;
    void maxDepth(TreeNode* root, int depth) {
        if(root==nullptr) return;
        if(root->left==nullptr&&root->right==nullptr) {
            result = max(result, depth);
        }
        maxDepth(root->left, depth+1);
        maxDepth(root->right, depth+1);
    } 

    int maxDepth(TreeNode* root) {
        maxDepth(root, 1);
        return result;
    }
};