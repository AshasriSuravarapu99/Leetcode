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
    long long sum = 0;
    long long maxi = 0;
    int mod = 1e9 + 7;
    void fun(TreeNode* root){
        if(root == nullptr) return;
        if(root->left != nullptr) fun(root->left);
        if(root -> right != nullptr) fun(root -> right);
        sum = (sum%mod + root->val) % mod;
    }
    void ans(TreeNode* root){
        if(root == NULL ) return;
        if(root->left != nullptr) ans(root->left);
        if(root->right != nullptr) ans(root -> right);
        if(root->right == nullptr && root->left == nullptr){
            maxi = max(maxi, (sum-root->val)*root->val);
        }
        else if(root->right == nullptr && root->left != nullptr){
            root->val = root->val + root->left->val;
            maxi = max(maxi, (sum-root->val)*root->val);
        }
        else if(root->right != nullptr && root->left == nullptr){
            root->val = root->val + root->right->val;
            maxi = max(maxi, (sum-root->val)*root->val);
        }
        else{
            root->val = root->val + root->right->val + root->left->val;
            maxi = max(maxi, (sum-root->val)*root->val);
        }

    }
    int maxProduct(TreeNode* root) {
        fun(root);
        ans(root);
        return maxi % mod;
    }
};