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
    int traverse(TreeNode* root,int val){
        if(root==NULL){
            return 0;
        }
        int temp=0;
        // if(root!=NULL&&root->left==NULL&&root->right==NULL){
        //     return 1;
        // }
        if(root->val >= val){
            temp=1;
        }
        val=max(val,root->val);
        return temp+traverse(root->right,val) +traverse(root->left,val);    
        
    }   
    int goodNodes(TreeNode* root) {
        return traverse(root,INT_MIN);
    }
};
