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