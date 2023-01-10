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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr && q==nullptr){
            return true;
        }
        else if(p==nullptr || q==nullptr){
            return false;
        }
        stack<TreeNode*> ps,qs;
        ps.push(p);
        qs.push(q);
        TreeNode m;
        m.val = INT_MAX;
        m.left = nullptr;
        m.right = nullptr;
        TreeNode *s, *t;
        while(ps.empty()!=true && qs.empty()!=true){
            s = ps.top();
            t = qs.top();
            ps.pop();
            qs.pop();
            if(s->val!=t->val){
                return false;
            }
            else{
                if(s->right==nullptr && t->right!=nullptr){
                    ps.push(&m);
                    qs.push(t->right);
                }
                else if(s->right!=nullptr && t->right==nullptr){
                    ps.push(s->right);
                    qs.push(&m);
                }
                else if(s->right!=nullptr && t->right!=nullptr){
                    ps.push(s->right);
                    qs.push(t->right);
                }
                if(s->left==nullptr && t->left!=nullptr){
                    ps.push(&m);
                    qs.push(t->left);
                }
                else if(s->left!=nullptr && t->left==nullptr){
                    ps.push(s->left);
                    qs.push(&m);
                }
                else if(s->left!=nullptr && t->left!=nullptr){
                    ps.push(s->left);
                    qs.push(t->left);
                }
            }
        }
        return true;
    }
};
