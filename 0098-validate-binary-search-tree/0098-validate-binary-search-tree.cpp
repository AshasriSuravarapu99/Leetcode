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
    bool isValid(TreeNode* root,long long mini, long long maxi){
        if(root == nullptr) return true;

        if(root->val <= mini || root->val >= maxi) return false;

        bool l = isValid(root->left,mini,root->val);
        bool r = isValid(root->right,root->val,maxi);

        return l && r;


    }
    bool isValidBST(TreeNode* root) {
       return isValid(root,LLONG_MIN,LLONG_MAX);
    }
};
