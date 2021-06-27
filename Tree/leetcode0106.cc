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
    TreeNode* buildTree1(vector<int> inorder, vector<int> postorder) {
        if(inorder.empty()) return nullptr;
        TreeNode* root = new TreeNode(postorder.back());
        auto iter = find(inorder.begin(), inorder.end(), postorder.back());
        size_t left_num = iter-inorder.begin();
        size_t right_num = inorder.end()-iter-1;
        root->left = buildTree1(vector<int>(inorder.begin(), iter), 
                                vector<int>(postorder.begin(), postorder.begin()+left_num));
        root->right = buildTree1(vector<int>(iter+1, inorder.end()),
                                vector<int>(postorder.begin()+left_num, postorder.end()-1));

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {


        return buildTree1(inorder, postorder);
    }
};
// 减少内存
class Solution1 {
public:
    TreeNode* buildTree(vector<int>& inorder, int in_st, int in_end, 
                        vector<int>& postorder, int po_st, int po_end) 
    {
        if(in_end<in_st||po_st>po_end) return nullptr;
        TreeNode* root = new TreeNode(postorder[po_end]);
        auto iter = find(inorder.begin()+in_st, inorder.begin()+in_end+1, root->val);
        int left_num = iter - inorder.begin()-in_st;
        root->left = buildTree(inorder, in_st, in_st+left_num-1, postorder, po_st, po_st+left_num-1);
        root->right = buildTree(inorder, in_st+left_num+1, in_end, postorder, po_st+left_num, po_end-1);
        return root;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
};