/* LeetCode 104 */
/* Better than 22.47% of submissions */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return max((root->left) ? maxDepth(root->left) : 0,
                   (root->right) ? maxDepth(root->right) : 0) + 1;
    }
};
