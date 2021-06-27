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
    TreeNode* buildTree1(vector<int> preorder, vector<int> inorder) {
        if(preorder.empty()) return nullptr;
        TreeNode* root = new TreeNode(preorder[0]);
        auto iter = find(inorder.begin(), inorder.end(), preorder[0]);
        size_t left_num = iter-inorder.begin();
        size_t right_num = inorder.end()-iter-1;
        root->left = buildTree1(vector<int>{preorder.begin()+1, preorder.begin()+1+left_num}, 
                                vector<int>(inorder.begin(), inorder.begin()+left_num));
        root->right = buildTree1(vector<int>(preorder.begin()+1+left_num, preorder.end()),
                                vector<int>(iter+1, inorder.end()));

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree1(preorder, inorder);
    }
};
// 减少内存和时间
class Solution1 {
public:
    TreeNode* buildTree(vector<int>& preorder, int pre_st, int pre_end,
                        vector<int>& inorder, int in_st, int in_end) 
    {
        if(pre_st>pre_end||in_st>in_end) return nullptr;
        TreeNode* root = new TreeNode(preorder[pre_st]);
        int index = in_st;
        while(inorder[index]!=root->val) index++;
        root->left = buildTree(preorder, pre_st+1, pre_st+index-in_st,
                                inorder, in_st, index-1);
        root->right = buildTree(preorder, pre_st+index-in_st+1, pre_end,
                                inorder, index+1, in_end);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
};