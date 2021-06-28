/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result;
        if(root==nullptr) return result;
        result += to_string(root->val);
        queue<TreeNode*> queTree;
        queTree.push(root);
        while(queTree.size()) {
            TreeNode* node = queTree.front(); queTree.pop();
            if(node->left) {
                result += " " + to_string(node->left->val);
                queTree.push(node->left);
            } else {
                result = result + " " + "#";
            }

            if(node->right) {
                result += " " + to_string(node->right->val);
                queTree.push(node->right);
            } else {
                result =  result + " " + "#";
            }
        }

        auto iter = find_if(result.rbegin(), result.rend(), [](char c){return c !='#'&&c!=' ';});
        result = result.substr(0, result.rend()-iter);

        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string str;
        ss>>str;
        TreeNode* root =nullptr;
        if(str.size()&&str!="#") {
            root = new TreeNode(stoi(str));
        } else {
            return root;
        }
        queue<TreeNode*> queTree;
        queTree.push(root);

        while(queTree.size()) {
            str.clear();
            TreeNode* node = queTree.front(); queTree.pop();
            ss >> str;
            if(str.size()&&str!="#") {
                node->left = new TreeNode(stoi(str));
                queTree.push(node->left);
            } else {
                node->left = nullptr;
            }
            str.clear();  // 当ss为空时，不修改str的值
            ss >> str;
            if(str.size()&&str!="#") {
                node->right = new TreeNode(stoi(str));
                queTree.push(node->right);
            } else {
                node->right = nullptr;
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));