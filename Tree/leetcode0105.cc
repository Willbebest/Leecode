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

class Solution2 {
public:
    TreeNode* buildTree(vector<int>& preorder, int pre_start, int pre_end,
                        vector<int>& inorder, int in_start, int in_end)
    {
        if(pre_start>pre_end||in_start>in_end) return nullptr;
        auto iter = find(inorder.begin(), inorder.end(), preorder[pre_start]);  // 假设没有重复元素
        int left_len = iter - inorder.begin() - in_start;
        TreeNode* node = new TreeNode(preorder[pre_start]);
        node->left = buildTree(preorder, pre_start+1, pre_start+left_len,
                               inorder, in_start, in_start+left_len-1);
        node->right = buildTree(preorder, pre_start+left_len+1, pre_end,
                                inorder, in_start+left_len+1, in_end);

        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, 0, preorder.size()-1,
                        inorder, 0, inorder.size()-1);
    }
};