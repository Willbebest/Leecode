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
    // 输入[] 0, 结果是false
    // bool hasPathSum(TreeNode* root, int targetSum) {
    //     if(root==nullptr&&targetSum==0) return true;
    //     if(root==nullptr&&targetSum!=0) return false;
    //     return hasPathSum(root->left, targetSum - root->val)||hasPathSum(root->right, targetSum - root->val);
    // }

    // 输入[1,2] 1, 结果是false
    // bool hasPathSum(TreeNode* root, int targetSum) {
    //     if(root==nullptr) return false;
    //     if(root->val == targetSum) return true;
    //     return hasPathSum(root->left, targetSum - root->val)||hasPathSum(root->right, targetSum - root->val);
    // }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==nullptr) return false;
        if(root->val == targetSum&&root->left==nullptr&&root->right==nullptr) return true;
        return hasPathSum(root->left, targetSum - root->val)||hasPathSum(root->right, targetSum - root->val);
    }
};


// 非递归法：利用层次遍历
class Solution1 {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==nullptr) return false;

        queue<TreeNode*> quuNode;
        queue<int> quuVal;
        quuNode.push(root);
        quuVal.push(targetSum);
        while(quuNode.size()&&quuVal.size()) {
            TreeNode* node = quuNode.front(); quuNode.pop();
            int val = quuVal.front(); quuVal.pop();

            if(node->val==val&&node->left==nullptr&&node->right==nullptr) return true;

            if(node->left) {
                quuNode.push(node->left);
                quuVal.push(val - node->val);
            }

            if(node->right) {
                quuNode.push(node->right);
                quuVal.push(val - node->val);
            }
        }

        return false;
    }
};