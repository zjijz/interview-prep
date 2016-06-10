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
        int height = 0;
        queue<TreeNode*> Q;
        if (root) Q.push(root);
        while (!Q.empty()) {
            height++;
            int size = Q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* popped = Q.front();
                Q.pop();
                if (popped->left) Q.push(popped->left);
                if (popped->right) Q.push(popped->right);
            }
        }
        return height;
    }
};
