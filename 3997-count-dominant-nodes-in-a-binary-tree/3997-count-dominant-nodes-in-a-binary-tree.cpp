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
    int ans = 0;
    int count(TreeNode* root){
        if(root == nullptr) return 0;

        int left = count(root->left);
        int right = count(root -> right);

        int val = root->val;
        if(val >= left && val >= right){
            ans++;
            return val;
        }
        else if(left > right) return left;
        else return right;
    }
    int countDominantNodes(TreeNode* root) {
        int a = count(root);
        return ans;
    }
};