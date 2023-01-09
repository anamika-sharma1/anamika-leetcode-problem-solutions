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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        vector<int> a;
        if(root!=nullptr){
            result.push_back(root->val);
            a = preorderTraversal(root->left);
            result.insert(result.end(), a.begin(), a.end());
            a = preorderTraversal(root->right);
            result.insert(result.end(), a.begin(), a.end());
        }
        return result;
    }
};
