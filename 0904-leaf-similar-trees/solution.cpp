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
 // using level order traversal 
class Solution {
public:
    void findLeaf(vector<int> &a,TreeNode* r){
        if(r==NULL) return;
        if(r->left==NULL&&r->right==NULL){
            a.push_back(r->val);
            return;
        }
        findLeaf(a,r->left);
        findLeaf(a,r->right);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> a,b;
        findLeaf(a,root1);
        findLeaf(b,root2);
        if(a.size()!=b.size()) return false;
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i]){
                return false;
            }
        }
        return true;
    }
};
