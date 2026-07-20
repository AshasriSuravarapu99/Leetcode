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
    int count(TreeNode* root, int &ans){
        if(root == nullptr) return 0;

        int left = count(root->left, ans);
        int right = count(root -> right, ans);

        int val = root->val;
        if(val >= left && val >= right){
            ans++;
            return val;
        }
        return max(left,right);
    }
    int countDominantNodes(TreeNode* root) {
        int ans= 0;
        int a = count(root,ans);
        return ans;
    }
};