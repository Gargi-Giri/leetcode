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
    TreeNode* recover(string &traversal, int &index, int depth) {
        if(index == traversal.length()) return NULL;
        int element = 0;
        while(index < traversal.length() && traversal[index] != '-') {
            element = (element*10) + int(traversal[index] - '0');
            index++;
        }
        TreeNode* root = new TreeNode(element);
        if(index == traversal.length()) return root;
        int currDepth = 0;
        while(index < traversal.length() && traversal[index] == '-') {
            currDepth++;
            index++;
        }
        if(currDepth <= depth) {
            index -= currDepth;
            return root;
        }
        root->left = recover(traversal, index, currDepth);
        currDepth = 0;
        while(index < traversal.length() && traversal[index] == '-') {
            currDepth++;
            index++;
        }
        if(currDepth <= depth) {
            index -= currDepth;
            return root;
        }
        root->right = recover(traversal, index, currDepth);
        return root;
    }
public:
    TreeNode* recoverFromPreorder(string traversal) {
        int ind=0;
        return recover(traversal, ind, 0);
    }
};
