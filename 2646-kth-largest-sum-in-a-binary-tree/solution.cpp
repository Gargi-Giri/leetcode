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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if(root==NULL) return -1;
        vector<long long> levelSums;
        queue<TreeNode*> q;
        int sum=0;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            long long levelSum=0;
            vector<int> level;
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                levelSum+=node->val;
                if(node->left!=NULL){
                    q.push(node->left);
                }
                if(node->right!=NULL){
                    q.push(node->right);
                }
                level.push_back(node->val);
                
            }
            levelSums.push_back(levelSum);
        }
        sort(levelSums.begin(),levelSums.end(),greater<long long>());
        if(k>levelSums.size()) return -1;
        return levelSums[k-1];
    }
};
