/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    void countGood(TreeNode* root, int maxi) {
        if (root == nullptr)
            return;
        maxi = max(maxi, root->val);
        if (maxi == root->val) {
            cout << root->val << " ";
            ans++;
        }

        countGood(root->left, maxi);
        countGood(root->right, maxi);

        return;
    }
    int goodNodes(TreeNode* root) {
        countGood(root, INT_MIN);
        return ans;
    }

};