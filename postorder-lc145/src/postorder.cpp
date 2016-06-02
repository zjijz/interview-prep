/* LeetCode 145 */
/* 0 ms, Better than 25ish% #/

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> S;
        if (root) S.push(root);
        while (!S.empty()) {
            TreeNode* popped = S.top();
            S.pop();

            if (!popped->left && !popped->right) {
                ret.push_back(popped->val);
            } else {
                S.push(popped);
                if (popped->right) S.push(popped->right);
                if (popped->left) S.push(popped->left);
                popped->left = NULL;
                popped->right = NULL;
            }
        }
        return ret;
    }
};
