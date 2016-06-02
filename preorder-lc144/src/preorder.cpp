/* Leetcode 144 */
/* Better than 22ish% */

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> S;
        if (root) S.push(root);
        while (!S.empty()) {
            TreeNode* popped = S.top();
            S.pop();
            ret.push_back(popped->val);
            if (popped->right) S.push(popped->right);
            if (popped->left) S.push(popped->left);
        }
        return ret;
    }
};
