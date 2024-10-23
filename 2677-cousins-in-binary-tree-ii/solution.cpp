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
#include <queue>

class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        if (!root) return nullptr;

        // Initialize a queue for BFS
        std::queue<TreeNode*> q;
        q.push(root);

        // We need to keep track of parent-child relationships
        root->val = 0;  // Root has no cousins, so we set its value to 0

        while (!q.empty()) {
            int levelSize = q.size();
            int levelSum = 0;  // Sum of all nodes at the current level

            // First pass: Calculate the total sum of values at this level
            std::vector<TreeNode*> nodesAtLevel;
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                nodesAtLevel.push_back(node);

                if (node->left) {
                    levelSum += node->left->val;
                    q.push(node->left);
                }
                if (node->right) {
                    levelSum += node->right->val;
                    q.push(node->right);
                }
            }

            // Second pass: Update each node's value with the sum of cousins
            for (TreeNode* node : nodesAtLevel) {
                int siblingSum = 0;
                if (node->left && node->right) {
                    siblingSum = node->left->val + node->right->val;
                } else if (node->left) {
                    siblingSum = node->left->val;
                } else if (node->right) {
                    siblingSum = node->right->val;
                }

                // For each child, set its value to the sum of the other nodes at this level
                if (node->left) {
                    node->left->val = levelSum - siblingSum;
                }
                if (node->right) {
                    node->right->val = levelSum - siblingSum;
                }
            }
        }

        return root;
    }
};

