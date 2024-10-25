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
private:
    bool Mirror(TreeNode *left,TreeNode * right){
        if(left==NULL&&right==NULL) return true;
        if(left==NULL||right==NULL) return false;
        return (left->val==right->val)&&Mirror(left->right,right->left)&&Mirror(left->left,right->right);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        return Mirror(root->left,root->right);
    }
};
