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
    bool ans = false;
    void sum(TreeNode* root, int total, int targetSum){
        if(root == nullptr){
            return;
        }
        if(ans) return;

        total+=root->val;
        if(root->left == nullptr && root->right == nullptr && targetSum == total) ans = true;
        sum(root->left,total,targetSum);
        sum(root->right,total,targetSum);

        return;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return false;
        sum(root,0,targetSum);
        return ans;
    }
};