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
    TreeNode* ans = nullptr;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val == p->val || root->val == q->val) {
            return root;
        }

        if(p->val > q->val){
            swap(p,q);
        } 

        if((p->val < root->val) && (q->val > root->val)){
            return root;
        }

        if((p->val < root->val) && (q->val < root->val)) 
        {
           ans = lowestCommonAncestor(root->left,p,q);
        }
        if(ans) return ans;
        else {
            ans=lowestCommonAncestor(root->right,p,q);
        }
        return ans;

    }
};