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
// class Solution {
// private:
//     int maxDepth(TreeNode* root){
//         if(root==NULL)  return 0;
//         int lh=maxDepth(root->left);
//         int rh=maxDepth(root->right);
//         return 1+max(lh,rh);
//     }
//     void deleteSubTree(TreeNode* &root){
//         if(root==NULL) return ;
//         deleteSubTree(root->left);
//         deleteSubTree(root->right);
//         delete root;
//         root=NULL;
//     }
//     bool removeNode(TreeNode* &root,int key){
//         if(root==NULL)  return false;
//         if(root->val==key){
//             deleteSubTree(root);
//             return true;
//         }
//         else if(root->left!=NULL&&root->left->val==key){
//             deleteSubTree(root->left);
//             root->left=NULL;
//             return true;
//         }
//         else if(root->right!=NULL&&root->right->val==key){
//             deleteSubTree(root->right);
//             root->right=NULL;
//             return true;
//         }
//         return removeNode(root->left,key)||removeNode(root->right,key);
//     }
//     TreeNode* cloneTree(TreeNode* root) {
//         if (root == NULL) return NULL;
//         TreeNode* newNode = new TreeNode(root->val);
//         newNode->left = cloneTree(root->left);
//         newNode->right = cloneTree(root->right);
//         return newNode;
//     }
//     vector<int> removeQuerie(TreeNode *root, vector<int>& queries) {
//         vector<int> result;
//         for (int query : queries) {
//             TreeNode* clonedRoot = cloneTree(root); // Clone the original tree
//             if (removeNode(clonedRoot, query)) {
//                 int heightAfter = maxDepth(clonedRoot); // Height after removal
//                 result.push_back(heightAfter-1);
//             } else {
//                 result.push_back(-1); // Node not found
//             }
//             deleteSubTree(clonedRoot); // Clean up cloned tree
//         }
//         return result;
//     }
// public:
//     vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
//         return removeQuerie(root,queries);
//     }
// };
class Solution {
public:
    // Array to store the maximum height of the tree after removing each node
    int maxHeightAfterRemoval[100001];
    int currentMaxHeight = 0;

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        traverseLeftToRight(root, 0);
        currentMaxHeight = 0;  // Reset for the second traversal
        traverseRightToLeft(root, 0);

        // Process queries and build the result vector
        int queryCount = queries.size();
        vector<int> queryResults(queryCount);
        for (int i = 0; i < queryCount; i++) {
            queryResults[i] = maxHeightAfterRemoval[queries[i]];
        }

        return queryResults;
    }

private:
    // Left to right traversal
    void traverseLeftToRight(TreeNode* node, int currentHeight) {
        if (node == nullptr) return;

        // Store the maximum height if this node were removed
        maxHeightAfterRemoval[node->val] = currentMaxHeight;

        // Update the current maximum height
        currentMaxHeight = max(currentMaxHeight, currentHeight);

        // Traverse left subtree first, then right
        traverseLeftToRight(node->left, currentHeight + 1);
        traverseLeftToRight(node->right, currentHeight + 1);
    }

    // Right to left traversal
    void traverseRightToLeft(TreeNode* node, int currentHeight) {
        if (node == nullptr) return;

        // Update the maximum height if this node were removed
        maxHeightAfterRemoval[node->val] =
            max(maxHeightAfterRemoval[node->val], currentMaxHeight);

        // Update the current maximum height
        currentMaxHeight = max(currentHeight, currentMaxHeight);

        // Traverse right subtree first, then left
        traverseRightToLeft(node->right, currentHeight + 1);
        traverseRightToLeft(node->left, currentHeight + 1);
    }
};

